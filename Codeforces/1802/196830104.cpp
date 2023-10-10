#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    ll t;
    cin >> t;

    while (t--> 0) {
        bool done = false;
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n+1, vector<ll>(m+1));

        if (n == 1 && m == 1){
            cout << 1 << endl;
            cout << 0 << endl;
            continue;
        }

        if (n%2 == 0 && m%2 == 0) {
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    a[i][j] = (1 << 16) * i + j * 2;
                    a[i + 1][j] = (1 << 16) * i + (j + 1) * 2;
                    a[i][j + 1] = (1 << 16) * i + j * 2 + 1;
                    a[i + 1][j + 1] = (1ull << 32) + (1 << 16) * (i+1) + (j + 1) * 2 + 1;
                }
            }
        } else if (n%2 && m%2){
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    a[i][j] = (1ull << 13) + (1 << 16) * (i + 1) + j * 2;
                    a[i + 1][j] = (1 << 16) * i + (j + 1) * 2;
                    a[i][j + 1] = (1 << 16) * i + j * 2 + 1;
                    a[i + 1][j + 1] = (1 << 16) * i + (j + 1) * 2 + 1;
                }
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                for (int j = 0; j < m; j += 2) {
                    a[i][j] = (1 << 16) * i + j * 2;
                    a[i + 1][j] = (1 << 16) * i + (j + 1) * 2;
                    a[i][j + 1] = (1 << 16) * i + j * 2 + 1;
                    a[i + 1][j + 1] = (1 << 16) * i + (j + 1) * 2 + 1;
                }
            }
        }

        cout << n * m << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
}