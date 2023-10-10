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
        string a, b, r;
        ll n, x, y, cnt = 0;
        cin >> n >> x >> y;
        cin >> a >> b;

        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i])
                r += '0';
            else
                r += '1', cnt++;
        }

        if (cnt%2){
            cout << -1;
        } else {
            bool done = false;
            for (int i = 0; i < n; ++i) {
                if (r[i] == r[i + 1] && r[i] == '1' && cnt == 2) {
                    cout << min(x, 2 * y);
                    done = true;
                    break;
                }
            }

            if (!done)
                cout << cnt/2 * y;
        }
        cout << endl;
    }
}