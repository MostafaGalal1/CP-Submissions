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

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, m, h, b, cur = 2;
        cin >> n >> m;

        set<pair<ll, ll>> se;
        bool done = false;

        for (int i = 3; i <= n && !done; ++i) {
            for (int j = 2; j < i && !done; ++j) {
                se.insert({i, j});
                if ((ll)se.size() >= (ll)(1e5+5))
                    done = true;
            }
        }

        vector<pair<ll, ll>> v, w;
        for (int i = 0; i < m; ++i) {
            cin >> h >> b;
            if (b)
                v.emplace_back(h, i);
            else
                w.emplace_back(h, i);
        }

        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        map<ll, pair<ll, ll>> mapp;
        map<ll, ll> c;

        for (int i = 0; i < (ll)v.size(); ++i)
            mapp[v[i].second] = {cur, 1}, c[cur++] = v[i].first;

        bool d = false;
        for (int i = 0; i < (ll)w.size(); ++i){
            pair<ll, ll> p = *se.begin();
            if (w[i].first < c[p.first])
                d = true;
            else {
                mapp[w[i].second] = {p.second, p.first};
                se.erase(se.begin());
            }
        }

        if (d)
            cout << -1;
        else {
            for (auto& mm : mapp)
                cout << mm.second.second << ' ' << mm.second.first << endl;
        }
    }

    return 0;
}