#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> aa(n), bb(n);
        map<ll, ll> a, b;

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> aa[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> bb[i];
        }

        for (int i = 0; i < n; ++i) {
            if (!i || aa[i] == aa[i-1])
                cnt++;
            else {
                a[aa[i-1]] = max(a[aa[i-1]], cnt);
                cnt = 1;
            }
        }
        a[aa[n-1]] = max(a[aa[n-1]], cnt);

        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!i || bb[i] == bb[i-1])
                cnt++;
            else {
                b[bb[i-1]] = max(b[bb[i-1]], cnt);
                cnt = 1;
            }
        }
        b[bb[n-1]] = max(b[bb[n-1]], cnt);

        ll mx = 1;
        for (auto & m : b)
            mx = max(mx, m.second);

        for (auto & m : a){
            if (b[m.first])
                mx = max(mx, a[m.first] + b[m.first]);
            else
                mx = max(mx, m.second);
        }

        cout << mx << endl;
    }

    return 0;
}
