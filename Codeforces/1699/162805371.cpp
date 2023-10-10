#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        cin >> n >> m;
        int arr[n][m];

        for (int j = 0; j < n / 2; j++) {
            for (int k = 0; k < m / 2; k++) {
                if (j % 2 == k % 2) {
                    arr[j * 2][k * 2] = 1;
                    arr[j * 2][k * 2 + 1] = 0;
                    arr[j * 2 + 1][k * 2] = 0;
                    arr[j * 2 + 1][k * 2 + 1] = 1;
                } else {
                    arr[j * 2][k * 2] = 0;
                    arr[j * 2][k * 2 + 1] = 1;
                    arr[j * 2 + 1][k * 2] = 1;
                    arr[j * 2 + 1][k * 2 + 1] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}