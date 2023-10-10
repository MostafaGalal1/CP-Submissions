#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, mx = 0;
        cin >> n;
        vector<ll> a(n), p(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        for (int i = 0; i < n; ++i) {
            cout << mx - a[i] + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
