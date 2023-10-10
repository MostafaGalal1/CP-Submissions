#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX - 1000;
const ll N = 52;

ll dist (pair<ll, ll> a, pair<ll, ll> b) {
    return (ll) sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    while (cin >> n >> m) {
        ll u, v, x, y, tot = 0, cur_max = 1;
        pair<ll, ll> pos[N];
        vector<pair<ll, pair<ll, ll>>> ve;
        ll arr[N][N], dis[N][N], tmp[N][N], tmpp[N][N];
        map<pair<ll, ll>, bool> mapp, exist;
        memset(dis, oo, sizeof(dis));
        memset(arr, oo, sizeof(arr));
        memset(tmp, oo, sizeof(tmp));

        if (!(n || m))
            break;

        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            pos[i] = {x, y};
            mapp[{x, y}] = mapp[{y, x}] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                exist[{i, j}] = exist[{j, i}] = true;
                dis[i][j] = dis[j][i] = dist(pos[i], pos[j]);
            }
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            u--, v--;
            exist.erase({u, v}), exist.erase({v, u});
            arr[u][v] = arr[v][u] = dis[u][v];
            tmp[u][v] = tmp[v][u] = dis[u][v];
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                tot += arr[i][j];
            }
        }

        memcpy(tmpp, tmp, sizeof(tmpp));
        for (auto & ch : exist) {
            ll new_tot = 0;
            tmp[ch.first.first][ch.first.second] = dis[ch.first.first][ch.first.second];

            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (tmp[i][j] > tmp[i][k] + tmp[k][j])
                            tmp[i][j] = tmp[i][k] + tmp[k][j];
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j)
                        continue;
                    new_tot += tmp[i][j];
                }
            }

            if (tot - new_tot > cur_max) {
                ve.clear();
                ve.emplace_back(ch.first.first + ch.first.second, ch.first);
                cur_max = tot - new_tot;
            } else if (tot - new_tot == cur_max) {
                ve.emplace_back(ch.first.first + ch.first.second, ch.first);
            }
            memcpy(tmp, tmpp, sizeof(tmp));;
        }

        sort(ve.begin(), ve.end());

        cout << (ve.empty()? "No road required" : to_string(ve[0].second.first + 1) + " " + to_string(ve[0].second.second + 1)) << endl;
    }
    return 0;
}