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

    ll n, res = 1;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll cmn = LONG_LONG_MAX, mind = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]/n < cmn){
            cmn = a[i]/n;
            mind = i;
        }
    }

    map<pair<ll,ll>, bool> v, vv;
    for (int i = 0; i < n; ++i){
        if (a[i]%n <= i && a[i]/n == cmn)
            v[{a[i], i}] = true;
        else if (a[i]%n <= i && a[i]/n == cmn + 1 && i < mind)
            vv[{a[i], i}] = true;
    }

    if (!v.empty()) {
        for (int i = 0; i < n; ++i) {
            if (v[{a[i], i}]){
                res = i + 1;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (vv[{a[i], i}] || a[i]/n == cmn){
                res = i + 1;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}