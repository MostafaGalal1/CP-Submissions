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

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (ll i = 0; i < n; ++i) {
            cin >> b[i];
        }

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        ll mn = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, a[i] - b[i]);
            mx = max(mx, a[i] - b[i]);
        }

        if (mn >= -1 && mx == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}