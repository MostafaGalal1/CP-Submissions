#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
const ll N = 1e5 + 5, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 3e5 + 10, inf = INT_MAX;

ld cdd(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld rd(ld degrees) {
    ld radians = degrees * (PI / 180.0);
    return radians;
}

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

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n ,m, nu;
        cin >> n >> m;
        map<ll, ll> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            mapp[nu]++;
        }

        vector<pair<ll, ll>> a;
        for (auto& mm : mapp)
            a.emplace_back(mm);

        n = (ll)a.size();
        for (int i = 1; i < n; ++i) {
            a[i].second *= a[i-1].second;
            a[i].second %= mod;
        }

        ll res = 0;
        for (int i = m-1; i < n; ++i) {
            if (a[i].first - a[i-m+1].first < m) {
                res += (a[i].second * (i-m<0?1:inv(a[i-m].second))) % mod;
                res %= mod;
            }
        }

        cout << res << endl;
    }
    return 0;
}