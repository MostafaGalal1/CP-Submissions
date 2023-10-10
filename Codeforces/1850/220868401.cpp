#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector<ll> dis(N);
void dfs(ll node, ll di, bool con, vector<vector<ll>>& adj, vector<bool>& vis, map<pair<ll, ll>, ll>& mapp) {
    vis[node] = true;
    dis[node] = di;
    for (auto ch : adj[node]) {
        if (!vis[ch] || con)
            dfs(ch, di + mapp[{node, ch}], con, adj, vis, mapp);
    }
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, m;
        cin >> n >> m;
        bool done = false;
        vector<vector<ll>> adj(n+1), c;
        map<pair<ll, ll>, bool> e;
        map<pair<ll, ll>, ll> mapp;

        for (int i = 0; i <= n; ++i) {
            dis[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            if (e[{u, v}]){
                if (mapp[{u, v}] != w)
                    done = true;
                continue;
            } else if (e[{v, u}]) {
                if (mapp[{v, u}] != -w)
                    done = true;
                continue;
            }
            e[{v, u}] = true;
            e[{u, v}] = true;
            mapp[{u, v}] = w;
            mapp[{v, u}] = -w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            c.push_back({u, v, w});
        }

        if (done) {
            cout << "NO" << endl;
            continue;
        }

        vector<bool> vis(n+1, false);
        for (int i = 1; i <= n; ++i) {
            if (!vis[i])
                dfs(i, 0, false, adj, vis, mapp);
        }

        for (int i = 0; i < (ll)c.size(); ++i) {
            if (dis[c[i][0]] + c[i][2] != dis[c[i][1]]) {
                done = true;
                break;
            }
        }

        if (done) {
            cout << "NO";
        } else
            cout << "YES";
        cout << endl;
    }
    return 0;
}