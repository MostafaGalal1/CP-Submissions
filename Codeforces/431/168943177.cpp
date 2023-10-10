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

    ll n = 5, mx = 0;
    vector<vector<ll>> arr(n ,vector(n, 0ll));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j)
                    continue;
                for (int l = 0; l < n; ++l) {
                    if (l == k || l == j || l == i)
                        continue;
                    for (int m = 0; m < n; ++m) {
                        if (m == l || m == k || m == j || m == i)
                            continue;
                        mx = max(mx, (arr[i][j] + arr[j][i]) + (arr[j][k] + arr[k][j]) + 2*(arr[k][l] + arr[l][k]) + 2*(arr[l][m] + arr[m][l]));
                    }
                }
            }
        }
    }

    cout << mx << endl;

    return 0;
}