#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 9999999;

int dis[2020][2020];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int xi, int yi, int nn, int mm){
    queue<pair<int, int>> q;
    q.emplace(xi, yi);
    int x, y;


    while (!q.empty()) {
        int nx, ny;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > nn || ny > mm)
                continue;

            if (dis[x][y] + 1 < dis[nx][ny]){
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, k, xx, yy, mx = 0;
    cin >> n >> m;
    cin >> k;

    for (auto & di : dis) {
        for (int & j : di) {
            j = inf;
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> xx >> yy;
        if (xx < 1 || yy < 1 || xx > n || yy > m)
            continue;
        dis[xx][yy] = 0;
        bfs(xx, yy, n, m);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mx < dis[i][j]){
                mx = dis[i][j];
                xx = i;
                yy = j;
            }
        }
    }

    cout << xx << " " << yy << endl;

    return 0;
}