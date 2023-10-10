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
        ll n, x;
        cin >> n >> x;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        sort(a.begin(), a.end());
        ll ii, iii;

        bool done = false;
        for (int i = 0; i < n; ++i) {
            ll sum = x-a[i].first;
            if (sum > 0) {
                for (int j = i + 1; j < n; ++j) {
                    auto it = lower_bound(a.begin()+j+1, a.end(), make_pair(sum - a[j].first, 0ll));
                    if (it != a.end() && it->first + a[j].first == sum){
                        done = true;
                        ii = j;
                        iii = it-a.begin();
                        break;
                    }
                }
            }
            if (done){
                cout << a[i].second << ' ' << a[ii].second << ' ' << a[iii].second;
                break;
            }
        }

        if (!done)
            cout << "IMPOSSIBLE";
        cout << endl;
    }

    return 0;
}