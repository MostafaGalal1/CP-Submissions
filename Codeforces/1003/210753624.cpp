#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return 1LL * a * b %mod;
}

ll add( ll a , ll b){
    return (a + b) %mod;
}

ll fp( ll b , ll p){
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp %mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 1; i <= n; ++i)
        res = mul(res, i);
    return res;
}

ll inv(ll i){
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

ll mex(vector<ll> a){
    set<ll> s;
    ll n = (ll)a.size();

    for (int i = 0; i < n; ++i)
        s.insert(a[i]);

    ll cu = 0;
    for(auto ch : s){
        if (ch != cu)
            break;
        cu++;
    }

    return cu;
}

bool compareBySize(const vector<ll>& vec1, const vector<ll>& vec2) {
    return vec1.size() > vec2.size();
}

vector<vector<ll>> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    vector<vector<ll>> factors(n+1);
    for (int i = 2; i * i <= n; i++) {
        factors[i].push_back(i);
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
                factors[j].push_back(i);
                factors[i].push_back(j);
            }
        }
    }
    return factors;
}

vector<ll> dis(3e5+10, inf), par(3e5+10);
void bfs(ll node, vector<vector<ll>> &v, map<ll,bool> &m){
    for (int i = 0; i < 3e5+10; ++i) {
        par[i] = i;
    }
    queue<ll> q;
    q.push(node);
    dis[node] = 1;
    map<ll, bool> h;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for(auto child : v[node]){
            if (m[node] && m[child] && dis[child] > dis[node] + 1) {
                par[child] = node;
                dis[child] = dis[node] + 1;
                q.push(child);
            } else if (m[node] && (!m[child] && child < node) && dis[child] > dis[node]) {
                par[child] = node;
                dis[child] = dis[node];
                q.push(child);
            } else if (!m[node] && m[child] && dis[child] > dis[par[node]] + 1){
                par[child] = par[node];
                dis[child] = dis[par[node]] + 1;
                q.push(child);
            }
        }
    }
}

bool vis[N];
ll dfs(ll node, vector<vector<ll>> &adj, vector<ll> &val){
    vis[node] = true;
    for (auto child : adj[node]){
        if (!vis[child])
            val[node] += dfs(child, adj, val);
    }
    if (!val[node])
        val[node]++;
    return val[node];
}

vector<ll> divi(ll n, ll num) {
    vector<ll> divisors;
    for (int i = 2; i * i < num; i++) {
        if (num % i == 0 && i != n/num && num/i != n/num) {
            divisors.push_back(i);
            if (i != num/i)
                divisors.push_back(num/i);
        }
    }

    return divisors;
}

int main() {
    ll t = 1;

    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;
        bool done = false;
        string s;


        for (int i = 0; i < min(a, b); ++i) {
            if (min(a, b) == a)
                s += "10";
            else
                s += "01";
        }

        for (int i = 0; i < max(a, b) - min(a, b); ++i) {
            if (max(a, b) == a)
                s += "0";
            else
                s += "1";
        }

        ll cur = 2*min(a,b);
        if (a == b)
            cur--;

        if (x >= min(a, b)) {
            for (int i = (cur % 2 == x % 2 ? 1 : 0); cur > x && i < a + b - 1; i += 4) {
                swap(s[i], s[i + 1]);
                cur -= 2;
            }
        } else {
            s = "";
            for (int i = 0; i < x-1; i+=2) {
                s += "01";
            }
            a -= x/2;
            b -= x/2;
            if (x%2 == 0) {
                for (int i = 0; i < b; ++i) {
                    s += "1";
                }
                for (int i = 0; i < a; ++i) {
                    s += "0";
                }
            } else {
                for (int i = 0; i < a; ++i) {
                    s += "0";
                }
                for (int i = 0; i < b; ++i) {
                    s += "1";
                }
            }
        }

        cout << s << endl;
    }

    return 0;
}