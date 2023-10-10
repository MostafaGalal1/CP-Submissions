#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 55;

int dx[] = {1, -1, 0 , 0};
int dy[] = {0, 0 , -1, 1};

bool connected = true;
int n, m;
char arr[N][N];
bool visited[N][N];

void dfs(int x, int y){
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx , ny;
        nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '.')
            continue;
        if (!visited[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0, srx1 = -1, sry1 = -1, srx2 = -1, sry2 = -1;
    queue<pair<int, int>> q;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '#') {
                q.emplace(i, j);
                cnt++;
                if (srx1 == -1)
                    srx1 = i, sry1 = j;
                else if (srx2 == -1)
                    srx2 = i, sry2 = j;
            }
        }
    }

    if (cnt > 2) {
        int sz = (int)q.size();
        for (int k = 0; k < sz; ++k) {
            memset(visited, false, sizeof(visited));
            int sx = q.front().first, sy = q.front().second;
            q.pop();
            arr[sx][sy] = '.';

            if (sx == srx1 && sy == sry1)
                dfs(srx2, sry2);
            else
                dfs(srx1, sry1);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (arr[i][j] == '#' && !visited[i][j]) {
                        connected = false;
                        break;
                    }
                }
                if (!connected)
                    break;
            }
            if (!connected)
                break;
            arr[sx][sy] = '#';
        }
        if (connected)
            cout << 2;
        else
            cout << 1;
    } else {
        cout << -1;
    }
    cout << endl;

    return 0;
}