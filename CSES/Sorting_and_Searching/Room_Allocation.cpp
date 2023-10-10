#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return (1LL * a * b)%mod;
}

ll add(ll a , ll b){
    return a + b %mod;
}

ll fp( ll b , ll p){
    if (p < 0)
        return 0;
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp%mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        multiset<pair<ll, ll>> q;
        vector<pair<pair<ll, ll>, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first.second >> a[i].first.first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        ll mx = 0, cnt = 1;
        vector<ll> res(n);
        for (int i = 0; i < n; ++i) {
            auto it = q.upper_bound(make_pair(a[i].first.second, 0));
            ll cur = 0;
            if (!q.empty() && it != q.begin())
                cur = prev(it)->second, q.erase(prev(it));
            res[a[i].second] = (cur?cur:cnt++);
            q.insert(make_pair(a[i].first.first, res[a[i].second]));
            mx = max(mx, (ll)q.size());
        }

        cout << mx << endl;
        for (ll r : res)
            cout << r << ' ';
        cout << endl;
    }

    return 0;
}