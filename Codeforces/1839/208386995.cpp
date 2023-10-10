#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, x, y;
        cin >> n;
        vector<ll> a(n+1);
        a[0] = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        if (a[n]) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        ll cnt = 0;
        for (int i = n; i > 0; --i) {
            if (a[i] == 1 && a[i - 1] == 0) {
                cout << cnt << ' ';
                cnt = 0;
            } else {
                cout << 0 << ' ';
                cnt++;
            }
            if (!a[i] && !a[i-1]) {
                cnt = 0;
            }
        }
        cout << endl;
    }

    return 0;
}
