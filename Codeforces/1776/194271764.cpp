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
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, e = 0, s, cnt = 0;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> s;
            cnt += (s-e)/120;
            e = s;
        }

        cnt += (1440-1-e)/120;

        if (cnt > 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}