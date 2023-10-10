#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, l, r;
        cin >> n;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        if (a == b)
            cout << 0;
        else {
            ll cn = 0, cnt = 1;

            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i])
                    cn++;
            }

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i])
                    cnt++;
            }

            cout << min(cnt, cn);
        }
        cout << endl;


    }

    return 0;
}