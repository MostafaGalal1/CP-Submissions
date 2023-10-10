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

vector<ll> sieveOfEratosthenes(ll n, map<ll, ll> & m) {
    vector<ll> isPrime(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (i <= n/2 && m[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] += m[i];
        }
        isPrime[i] += m[i];
    }
    return isPrime;
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

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, x, y;
        cin >> n;
        map<ll, ll> v, h, hv, vh;

        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v[x]++, h[y]++;
            hv[y-x]++;
            vh[y+x]++;
        }

        ll res = 0;
        for (auto& m:v)
            res += m.second * (m.second - 1);
        for (auto& m:h)
            res += m.second * (m.second - 1);
        for (auto& m:vh)
            res += m.second * (m.second - 1);
        for (auto& m:hv)
            res += m.second * (m.second - 1);

        cout << res << endl;
    }
    return 0;
}