#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6+7, mod = 1e9+7;

ll add (ll a , ll b) {
    return (a % mod + b % mod) + mod % mod;
}

ll mul ( ll a , ll b) {
    return 1LL * a * b % mod;
}

ll fp( ll b , ll p) {
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

ll fact[N], inv[N];
void build() {
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (ll i = 2; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (ll i = 2; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
}

ll nCr(ll n , ll r) {
    return mul(fact[n],mul(inv[n-r],inv[r]));
}

ll nPr(ll n, ll r) {
    ll ans = nCr(n, r); ans *= fact[r];
    ans %= mod;
    return ans;
}

int main()
{
    ll t;
    cin >> t;
//    t = 1;

    build();
    while(t --> 0) {
        ll a, b;
        cin >> a >> b;
        cout << nCr(a, b) << endl;
    }

    return 0;
}