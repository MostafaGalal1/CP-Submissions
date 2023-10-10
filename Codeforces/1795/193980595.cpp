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

    ll n, cnt = 1;
    cin >> n;

    for (int i = 0; i < n/3; ++i) {
        vector<ll> arr(3);
        for (int j = 0; j < 3; ++j)
            cin >> arr[j];
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[1]){
            if (arr[1] == arr[2])
                cnt = mul(cnt, 3);
            else
                cnt = mul(cnt, 2);
        }
    }

    ll dm = fact(n/6);
    cout << mul(mul(fact(n/3), inv(mul(dm, dm))), cnt) << endl;

    return 0;
}