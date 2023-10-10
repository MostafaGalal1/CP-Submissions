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

    ll n, m;
    cin >> n >> m;
    vector<ll> p(n+1), q(m+1);

    for (int i = 0; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i <= m; ++i) {
        cin >> q[i];
    }

    if (n > m)
        cout << (p[0] * q[0] < 0? "-":"") << "Infinity" << endl;
    else if (n < m)
        cout << "0/1";
    else {
        ll dm = __gcd(p[0], q[0]);
        cout << (p[0] * q[0] < 0? "-":"") << abs(p[0] / dm) << "/" << abs(q[0] / dm) << endl;
    }

    return 0;
}