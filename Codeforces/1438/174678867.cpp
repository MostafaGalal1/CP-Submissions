#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2){
                    if (arr[i][j] % 2 == 0) {
                        arr[i][j]++;
                    }
                } else {
                    if (arr[i][j] % 2) {
                        arr[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}