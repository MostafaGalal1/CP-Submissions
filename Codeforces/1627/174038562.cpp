#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        int n, m, r, c;
        bool b0 = false, b1 = false, b2 = false;
        cin >> n >> m >> r >> c;
        r--, c--;

        char arr[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 'B') {
                    if (i == r && j == c) {
                        b0 = true;
                    } else if (i == r || j == c) {
                        b1 = true;
                    } else {
                        b2 = true;
                    }
                }
            }
        }

        if (b0)
            cout << 0;
        else if (b1)
            cout << 1;
        else if (b2)
            cout << 2;
        else
            cout << -1;
        cout << endl;

    }

    return 0;
}