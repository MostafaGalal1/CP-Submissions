#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, m, nu;
        bool d = false;
        cin >> n >> m;
        multiset<ll> ms;

        for (int i = 0; i < m; ++i) {
            cin >> nu;
            ms.insert(nu);
        }

        ll cnt = 0, res = 0;
        while (n){
            if (n & 1) {
                auto it = ms.lower_bound(1ll << cnt);
                if (it == ms.end()) {
                    d = true;
                    break;
                }

                nu = *it;
                while (nu > (1ll << cnt)) {
                    ms.erase(ms.find(nu));
                    nu >>= 1;
                    ms.insert(nu);
                    ms.insert(nu);
                    res++;
                }

                ms.erase(ms.find(1ll << cnt));
            }
            while (ms.size() > 1) {
                auto is = ms.begin();
                if (*is == (1ll << cnt) && *next(is) == (1ll << cnt)) {
                    ms.erase(ms.begin());
                    ms.erase(ms.begin());
                    ms.insert(1ll << (cnt + 1));
                } else
                    break;
            }
            if (*ms.begin() == (1ll << cnt))
                ms.erase(ms.begin());
            n >>= 1;
            cnt++;
        }

        if (d)
            cout << -1;
        else
            cout << res;
        cout << endl;
    }
    return 0;
}