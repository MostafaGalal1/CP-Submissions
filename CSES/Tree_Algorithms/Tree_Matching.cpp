#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 998244353;
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
    temp = mul(temp,temp)%mod;
    if(p&1)
        temp = mul(temp,b);
    return temp%mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
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

vector<ll> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    vector<ll> v;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            if (i * i <= n) {
                v.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                    isPrime[j] = false;
            } else
                v.push_back(i);
        }
    }
    return v;
}

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i)
                r.push_back(n / i);
        }
    }
    return r;
}

void primeFactors(ll n, map<ll, ll>& m) {
    while (n % 2 == 0) {
        m[2]++;
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 2)
        m[n]++;
}

ll fibonacci(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    double fn = (pow(phi, n) - pow(psi, n)) / sqrt(5);
    return static_cast<ll>(round(fn));
}

pair<ll, bool> dfs(ll node, vector<vector<ll>>& adj, vector<bool>& vis){
    vis[node] = true;
    ll res = 0;
    bool f = false;
    for(auto ch : adj[node]) {
        if (!vis[ch]) {
            pair<ll, bool> p = dfs(ch, adj, vis);
            res += p.first - (p.second?1:0);
            f |= p.second;
        }
    }
    res += (f?1:0);
    return make_pair(res + (f?0:1), !f);
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, x, y;
        cin >> n;

        vector<vector<ll>> adj(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        pair<ll, bool> p = dfs(0, adj, vis);
        cout << p.first - (p.second?1:0) << endl;
    }
    return 0;
}