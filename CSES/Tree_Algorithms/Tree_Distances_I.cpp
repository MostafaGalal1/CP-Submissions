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

void dfs (ll node, ll p, ll val, vector<ll>& res, vector<ll>& par, vector<vector<ll>>& g, vector<bool>& vis) {
    vis[node] = true;
    par[node] = p;
    for (auto ch : g[node])
        if (!vis[ch])
            dfs(ch, node, val + 1, res, par, g, vis);
    res[node] = val;
}

void dp (ll node, ll val, ll mx, bool b, vector<ll>& res, vector<vector<ll>>& g, vector<bool>& vis) {
    vis[node] = true;
    res[node] = val;
    for (auto ch : g[node])
        if (!vis[ch])
            dp(ch, val + (b && mx % 2 && res[ch] == mx / 2 ? 0 : 1), false, mx, res, g, vis);
}

int main() {
    fast();
    ll t;
    t = 1;
//    cin >> t;

    while (t --> 0) {
        ll n, x, y, mx = 0, mxi = 1;
        cin >> n;
        vector<vector<ll>> g(n+1);
        vector<ll> res(n+1, 0), par(n+1, 0);
        vector<bool> vis(n+1, false);

        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(1, 0, 0, res, par, g, vis);
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            par[i] = 0;
            if (mx < res[i])
                mx = res[i], mxi = i;
        }

        dfs(mxi, 0, 0, res, par, g, vis);
        mx = 0;
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            if (mx < res[i])
                mx = res[i], mxi = i;
        }
        while (res[mxi] != (mx+1)/2)
            mxi = par[mxi];

        dp(mxi, (mx+1)/2, mx, true, res, g, vis);
        for (int i = 1; i <= n; ++i)
            cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}