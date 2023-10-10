#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX, N = 510;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    t = 1;

    while(t-- > 0)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        ll u, v, w;
        ll arr[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = oo;
            }
            arr[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            u--, v--;
            arr[u][v] = min(arr[u][v], w);
            arr[v][u] = arr[u][v];
        }

        for (ll k = 0; k < n; k++)
            for (ll i = 0; i < n; i++)
                for (ll j = 0; j < n; j++)
                    if (arr[i][k] != LONG_LONG_MAX && arr[k][j] != LONG_LONG_MAX && arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];

        for (int i = 0; i < q; ++i) {
            cin >> u >> v;
            u--, v--;
            cout << (arr[u][v]==oo?-1:arr[u][v]) << '\n';
        }
    }

    return 0;
}