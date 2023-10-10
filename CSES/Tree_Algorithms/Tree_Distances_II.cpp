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

pair<ll, ll> dfs1 (ll node, vector<ll>& res, vector<ll>& siz, vector<vector<ll>>& g, vector<bool>& vis) {
    vis[node] = true;
    ll val = 0, cnt = 0;
    for (auto & ch : g[node]){
        if (!vis[ch]) {
            pair<ll, ll> p = dfs1(ch, res, siz, g, vis);
            val += p.first;
            cnt += p.second;
        }
    }
    res[node] = val + cnt;
    siz[node] = cnt;
    return {val + cnt, cnt+1};
}

void dfs2 (ll node, ll par, vector<ll>& res, vector<ll>& siz, vector<ll>& ans, vector<vector<ll>>& g, vector<bool>& vis) {
    vis[node] = true;
    if (node != 1)
        ans[node] = ans[par] + siz[1] - 1 - 2 * siz[node];
    for (auto &ch: g[node]) {
        if (!vis[ch])
            dfs2(ch, node, res, siz, ans, g, vis);
    }
}

int main() {
    fast();
    ll t;
    t = 1;
//    cin >> t;

    while (t --> 0) {
        ll n, x, y;
        cin >> n;
        vector<vector<ll>> g(n+1);
        vector<ll> siz(n+1, 0), res(n+1, 0), ans(n+1);
        vector<bool> vis(n+1, false);

        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs1(1, res, siz, g, vis);
        for (int i = 0; i <= n; ++i)
            vis[i] = false;
        ans[1] = res[1];
        dfs2(1, 0, res, siz, ans, g, vis);

        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}