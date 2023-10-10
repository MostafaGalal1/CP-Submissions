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

vector<bool> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

ll divis(ll n) {
    ll r = 1;
    for (ll i = 1; i <= n/2; ++i) {
        if (n%r)
            return r;
        r++;
    }
    return r;
}

void dfs (ll node, ll val, vector<ll>& res, vector<vector<ll>>& g, vector<bool>& vis) {
    vis[node] = true;
    for (auto ch : g[node])
        if (!vis[ch])
            dfs(ch, val + 1, res, g, vis);
    res[node] = val;
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
        vector<ll> res(n+1, 0);
        vector<bool> vis(n+1, false);

        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(1, 0, res, g, vis);
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            if (mx < res[i])
                mx = res[i], mxi = i;
        }
        dfs(mxi, 0, res, g, vis);

        cout << *max_element(res.begin(), res.end()) << endl;
    }
    return 0;
}