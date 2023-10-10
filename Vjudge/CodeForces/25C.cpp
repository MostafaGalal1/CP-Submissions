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

    ll n, m, u, v, c, tot = 0;

    cin >> n;

    ll arr[n][n];
    stack<ll> st, rs;
    vector<ll> ve;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; i++) {
            for (ll j= 0; j < n; j++ ) {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
                if (k == n-1 && i > j)
                    tot += arr[i][j];
            }
        }
    }

    cin >> m;

    for (ll k = 0; k < m; ++k) {
        cin >> u >> v >> c;
        u--, v--;
        if (arr[u][v] > c) {
            tot = 0;
            arr[u][v] = arr[v][u] = c;
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (arr[i][j] > arr[i][u] + arr[u][j])
                        arr[i][j] = arr[j][i] = arr[i][u] + arr[u][j];
                    if (arr[i][j] > arr[i][v] + arr[v][j])
                        arr[i][j] = arr[j][i] = arr[i][v] + arr[v][j];
                    if (i > j)
                        tot += arr[i][j];
                }
            }
        }
        cout << tot << ' ';
    }

    cout << endl;
    return 0;
}