#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 200;
vector<pair<ll, ll>> ve;

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

ll n, m;
char arr[N][N];
ll dis[N][N];

void bfs(){
    queue<pair<ll, ll>> q;
    for (auto & i : ve) {
        q.emplace(i.first, i.second);
        dis[i.first][i.second] = 0;
    }

    while (!q.empty()){
        ll x, y, nx, ny;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dis[nx][ny] > dis[x][y] + 1){
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t --> 0) {
        cin >> n >> m;

        ve.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                arr[i][j] = '0';
                dis[i][j] = oo;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == '1')
                    ve.emplace_back(i, j);
            }
        }

        bfs();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dis[i][j] << " ";
            }
            cout << endl;;
        }
    }
    return 0;
}