#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll oo = INT_MAX;
const ll N = 510;

map<string, ll> mapp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, m, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX;
        cin >> n >> m;
        ll arr[n][m];
        pair<ll, ll> v;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] > mx) {
                    mx = arr[i][j];
                    v = {i, j};
                }
            }
        }

        mn = (max(v.first, n-1-v.first)+1) * (max(v.second, m-1-v.second)+1);
        cout << mn << endl;
    }
    return 0;
}