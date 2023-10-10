#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9 + 7;
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
    return temp %mod;
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

    ll n, res = 0;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n-1; ++i)
        res = add(res, mul(a[n-1-i] - a[0], fp(2, n-2-i)));

    ll sum = res;
    for (int i = 1; i < n-1; ++i) {
        ll tmp = add(res,-add(add(mul(a[i] - a[i - 1], add(fp(2, n - 1 - i), -1)), mul(add(res, a[i - 1] - a[i]), inv(2))),a[i] - a[i - 1]));
        sum = add(sum, tmp);
        res = tmp;
    }

    cout << (sum+mod)%mod << endl;
}