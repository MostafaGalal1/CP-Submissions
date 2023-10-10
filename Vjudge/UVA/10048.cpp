#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 510;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q, t = 1;
    cin >> n >> m >> q;

    while(n || m || q) {
        ll u, v, w;
        ll arr[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = oo;
            }
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            u--, v--;
            arr[u][v] = w;
            arr[v][u] = w;
        }

        for (ll k = 0; k < n; ++k) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (arr[i][j] > max(arr[i][k], arr[k][j]))
                        arr[i][j] = max(arr[i][k], arr[k][j]);
                }
            }
        }

        cout << "Case #" << t << endl;
        for (int i = 0; i < q; ++i) {
            cin >> u >> v;
            u--, v--;
            if (arr[u][v] == INT_MAX)
                cout << "no path";
            else
                cout << arr[u][v];
            cout << endl;
        }

        t++;
        cin >> n >> m >> q;
        if (n || m || q)
            cout << endl;;
    }

    return 0;
}