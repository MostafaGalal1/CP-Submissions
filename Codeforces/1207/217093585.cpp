#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
const ll N = 3e6+10, mod = 998244353;
ll add ( ll a , ll b)
{
    return ((a % mod + b % mod) + mod) % mod;
}
ll mul ( ll a , ll b)
{
    return 1LL * a * b % mod;
}
ll fp( ll b , ll p)
{
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

ll fact[N], inv[N];
void build()
{
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (ll i = 2; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
ll nCr( ll n , ll r)
{
    return mul(fact[n],mul(inv[n-r],inv[r]));
}
ll nPr(ll n, ll r)
{
    ll ans = nCr(n, r); ans *= fact[r];
    ans %= mod;
    return ans;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n;
        cin >> n;
        build();
        vector<pair<ll, ll>> a(n);
        map<ll, ll> m1, m2;
        map<ll, map<ll, ll>> m3;
        
        for (ll i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            m1[a[i].first]++, m2[a[i].second]++;
            m3[a[i].first][a[i].second]++;
        }
        
        sort(a.begin(), a.end());

        bool r = false;
        for (ll i = 0; i < n-1; ++i) {
            if (a[i].second > a[i+1].second) {
                r = true;
                break;
            }
        }

        ll res1 = 1, res2 = 1, res3 = 1;
        for (auto & m : m1)
            res1 *= fact[m.second], res1 %= mod;
        for (auto & m : m2)
            res2 *= fact[m.second], res2 %= mod;
        for (auto & m : m3)
            for (auto & mm : m.second)
                res3 *= fact[mm.second], res3 %= mod;
        
        ll ans = fact[n] + 2*mod - res1 - res2 + (r?0:res3);
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}