#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll siz = 1e9+10, inf = LONG_LONG_MAX;

ll r1, c1, r2, c2, n;
map<ll, map<ll, bool>> arr;
map<ll, map<ll, ll>> dis;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

ll bfs(ll r, ll c){
    queue<pair<int ,int>> q;
    q.emplace(r, c);
    dis[r][c] = 0;

    while (!q.empty()){
        ll nr, nc;
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            nr = r + dx[i];
            nc = c + dy[i];

            if (arr[nr][nc] && dis[r][c] + 1 < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + 1;
                q.emplace(nr, nc);
            }
            if (nr == r2 && nc == c2)
                return dis[r2][c2];
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll u, a, b;
    cin >> r1 >> c1 >> r2 >> c2 >> n;

    map<ll, map<ll, bool>> empty1;
    map<ll, map<ll, ll>> empty2;
    swap(arr, empty1);
    swap(dis, empty2);

    for (ll i = 0; i < n; ++i) {
        cin >> u >> a >> b;
        for (ll j = a; j <= b; ++j) {
            arr[u][j] = true;
            dis[u][j] = inf;
        }
    }

    cout << bfs(r1, c1) << endl;

    return 0;
}