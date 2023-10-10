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
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    for (int i = 1; i < n; ++i) {
        a[i] -= b[i-1];
    }

    ll mx = 0, cn, mind = 0;
    for (int i = 0; i < n; ++i) {
        cn = 0;
        for (int j = 0; j < n; ++j) {
            if (j > mind) {
                if (b[j] - (b[i] + (j - i) * k) == 0)
                    cn++;
            } else {
                if (b[j] - (b[i] - (j - i) * k) == 0)
                    cn++;
            }
        }
        if (mx < cn && b[i] - k*i > 0){
            mx = cn;
            mind = i;
        }
    }

    cout << n - mx << endl;
    for (int i = 0; i < n; ++i) {
        if (i > mind) {
            if (b[i] - (b[mind] + (i - mind) * k) > 0)
                cout << '-' << ' ' << i + 1 << ' ' << abs(b[i] - (b[mind] + (i - mind) * k)) << endl;
            else if (b[i] - (b[mind] + (i - mind) * k) < 0)
                cout << '+' << ' ' << i + 1 << ' ' << abs(b[i] - (b[mind] + (i - mind) * k)) << endl;
        } else {
            if (b[i] - (b[mind] - (mind - i) * k) > 0)
                cout << '-' << ' ' << i + 1 << ' ' << abs(b[i] - (b[mind] - (mind - i) * k)) << endl;
            else if (b[i] - (b[mind] - (mind - i) * k) < 0)
                cout << '+' << ' ' << i + 1 << ' ' << abs(b[i] - (b[mind] - (mind - i) * k)) << endl;
        }
    }
    return 0;
}