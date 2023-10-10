#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, k, h;
        cin >> n >> k >> h;

        vector<ll> a(n), b(n);
        multiset<ll> ms;

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        for (int i = 0; i < n; ++i)
            ms.insert(abs(a[i] - b[i]));

        for (int i = 0; i < k+h; ++i) {
            ll num = *prev(ms.end());
            ms.erase(prev(ms.end()));
            ms.insert(abs(num-1));
        }

        ll res = 0;
        for (ll m : ms)
            res += m * m;

        cout << res << endl;
    }
    return 0;
}