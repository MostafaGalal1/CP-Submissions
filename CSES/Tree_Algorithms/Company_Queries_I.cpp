#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9+7, modp = 1e9 + 6;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return 1ll * a * b % mod;
}

ll mulp( ll a,  ll b){
    return 1ll * a * b % modp;
}

ll add( ll a , ll b){
    return (a + b + mod) % mod;
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

ll fpp( ll b , ll p){
    if(!p)
        return 1;
    ll temp = fpp(b,p/2);
    temp = mulp(temp,temp)%modp;
    if(p&1)
        temp = mulp(temp,b);
    return temp%modp;
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

    ll cu = 1;
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

map<ll,ll> primeFactors(ll n) {
    map<ll, ll> m;
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
    return m;
}

void dfs(ll node, ll cur, vector<vector<ll>>& adj, vector<bool>& vis, vector<vector<ll>>& a, map<ll, ll>& conn, vector<ll>& place, vector<ll>& ind) {
    vis[node] = true;
    a[cur].push_back(node);
    place[node] = cur;
    ind[node] = (ll)a[cur].size() - 1;
    ll next = cur;

    bool branch = adj[node].size() > 2 || (node == 1 && adj[node].size() > 1);
    for (auto ch : adj[node]) {
        if (!vis[ch]) {
            if (branch) {
                next++;
                conn[next] = cur;
            }
            dfs(ch, next, adj, vis, a, conn, place, ind);
        }
    }
}

void lca(ll node, ll l, vector<vector<ll>>& g, vector<bool>& vis, vector<ll>& depth, vector<vector<ll>>& up){
    vis[node] = true;
    for (ll ch : g[node]){
        depth[ch] = depth[node]+1;
        up[ch][0] = node;
        for (int i = 1; i < l; ++i)
            up[ch][i] = up[up[ch][i-1]][i-1];
        lca(ch, l, g, vis, depth, up);
    }
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, q, l, x, k;
        cin >> n >> q;
        l = (ll)ceil(log2(n))+1;

        vector<vector<ll>> g(n+1), up(n+1, vector<ll>(l, 0));
        vector<bool> vis(n+1, false);
        vector<ll> depth(n+1, 0);

        for (int i = 2; i <= n; ++i) {
            cin >> x;
            g[x].push_back(i);
        }

        lca(1, l, g, vis, depth, up);

        for (int i = 0; i < q; ++i) {
            cin >> x >> k;
            for (int j = 0; j < l && x; ++j)
                if (k & (1 << j))
                    x = up[x][j];
            if (x)
                cout << x;
            else
                cout << -1;
            cout << endl;
        }
    }
    return 0;
}