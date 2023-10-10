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

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll c, x, y;
        cin >> c;
        map<ll, ll> m;

        vector<pair<ll, ll>> v;
        ll cnt = 1, cntt = 1, sum = 1, prd = 1;
        for (int i = 0; i < c; ++i) {
            cin >> x >> y;
            cnt = mul(cnt, (y + 1));
            sum = mul(sum, mul(add(fp(x, y+1), -1), inv(add(x, -1))));
            prd = mul(fp(prd, y + 1), fp(fp(x, (y * (y + 1) / 2)), cntt));
            cntt = mulp(cntt, (y + 1));
        }
        cout << cnt << ' ' << sum << ' ' << prd << endl;
    }
    return 0;
}