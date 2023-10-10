#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

        bool tri = false, seg = false;
        ll d[4];
        cin >> d[0] >> d[1] >> d[2] >> d[3];

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j)
                    continue;
                for (int k = 0; k < 4; ++k) {
                    if (k == i || k == j)
                        continue;
                    if (d[i] + d[j] > d[k] && d[k] + d[j] > d[i] && d[i] + d[k] > d[j]) {
                        tri = true;
                    } else if (d[i] + d[j] == d[k] || d[k] + d[j] == d[i] || d[i] + d[k] == d[j]) {
                        seg = true;
                    }
                }
            }
        }

        if (tri)
            cout << "TRIANGLE";
        else if (seg)
            cout << "SEGMENT";
        else
            cout << "IMPOSSIBLE";
        cout << endl;

    return 0;
}