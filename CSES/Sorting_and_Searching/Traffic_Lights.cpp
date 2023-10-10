#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return (1LL * a * b)%mod;
}

ll add(ll a , ll b){
    return a + b %mod;
}

ll fp( ll b , ll p){
    if (p < 0)
        return 0;
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
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

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, x, nu;
        cin >> x >> n;
        set<ll> a;
        map<ll, ll> mapp;

        ll mx = 0;
        a.insert(0), a.insert(x);
        for (int i = 0; i < n; ++i) {
            cin >> nu;
            mapp[i] = nu;
            a.insert(nu);
        }

        auto is = a.begin();
        while (is != a.end()){
            if (is != a.begin())
                mx = max(mx, *is - *prev(is));
            is = next(is);
        }

        vector<ll> res(n);
        res[n-1] = mx;
        for (int i = n-1; i > 0; --i) {
             auto it = a.lower_bound(mapp[i]);
             res[i-1] = mx = max(mx, *next(it) - *prev(it));
             a.erase(it);
        }

        for (int i = 0; i < n; ++i) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}