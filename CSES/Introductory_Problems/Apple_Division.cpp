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
        ll n, res = LONG_LONG_MAX;
        cin >> n;
        vector<ll> a(n);
        vector<ll> dp(1<<n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < 1<<n; ++i) {
            ll s = 0;
            for (int j = 0; j < n; ++j)
                s += (((i>>j)&1)?a[j]:0);
            dp[i] = s;
        }

        for (int i = 0; i < 1<<n; ++i) {
            bitset<32> b(i);
            for (int j = 0; j < n; ++j)
                b[j].flip();
            res = min(res, abs(dp[i] - dp[b.to_ulong()]));
        }

        cout << res << endl;
    }

    return 0;
}