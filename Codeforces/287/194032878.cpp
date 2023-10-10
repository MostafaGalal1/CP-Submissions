#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 998244353;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b)
{
    return 1LL * a * b %mod;
}
ll add( ll a , ll b)
{
    return (a + b) %mod;
}
ll fp( ll b , ll p){
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 1; i <= n; ++i)
        res = mul(res, i);
    return res;
}

ll inv(ll i) {
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

int main()
{
    fast();

    ll n, k;
    cin >> n >> k;

    ll m = k * (k+1) / 2 - k + 1 - n;
    if (m < 0)
        cout << -1;
    else {
        long double a = (-1.0 + sqrtl(1 + 8 * (m+1))) / 2.0;
        long double b = (-1.0 - sqrtl(1 + 8 * (m+1))) / 2.0;
        if (a >= 0)
            cout << k - (ll)ceil(a);
        else
            cout << k - (ll)ceil(b);
        cout << endl;
    }

    return 0;
}