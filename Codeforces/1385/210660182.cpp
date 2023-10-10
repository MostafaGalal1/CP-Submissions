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

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, m, x, y, z;
        cin >> n >> m;

        vector<vector<ll>> arr(n, vector<ll>());
        vector<pair<ll, ll>> un;
        vector<ll> in(n, 0);

        for (int i = 0; i < m; i++){
            cin >> z;
            cin >> x >> y;
            x--, y--;
            if (z) {
                arr[x].push_back(y);
                in[y]++;
            } else {
                un.emplace_back(x, y);
            }
        }

        queue<ll> q;
        for (int i = 0; i < n; i++){
            if (!in[i])
                q.push(i);
        }

        ll cnt = 0;
        vector<ll> a;
        while(!q.empty()){
            ll node = q.front();
            a.push_back(node);
            cnt++;
            q.pop();
            for (ll & i : arr[node]){
                in[i]--;
                if (!in[i])
                    q.push(i);
            }
        }

        map<ll, ll> mapp;
        for (int i = 0; i < (ll)a.size(); ++i) {
            mapp[a[i]] = i;
        }

        if (cnt == n) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < (ll)arr[i].size(); ++j) {
                    cout << i+1 << ' ' << arr[i][j]+1 << endl;
                }
            }
            for (auto & i : un) {
                if (mapp[i.first] < mapp[i.second])
                    cout << i.first+1 << ' ' << i.second+1 << endl;
                else
                    cout << i.second+1 << ' ' << i.first+1 << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}