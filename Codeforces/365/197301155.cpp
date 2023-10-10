#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return 1LL * a * b %mod;
}

ll add( ll a , ll b){
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

ll inv(ll i){
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

ll func (ll n, ll k, vector<ll> & a){
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += min(a[j], k);
    }
    return sum;
}

int main() {
    fast();
    ll t;
    cin >> t;

    vector<ll> a(t);

    for (int i = 0; i < t; ++i) {
        cin >> a[i];
    }

    ll res = 0, cnt = 0;
    for (int i = 2; i < t; ++i) {
        if (a[i] == a[i-1] + a[i-2]){
            cnt++;
        } else {
            res = max(res, cnt);
            cnt = 0;
        }
    }

    cout << min(max(res, cnt)+2, t) << endl;
    return 0;
}