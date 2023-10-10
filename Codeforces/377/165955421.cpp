#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 510, inf = INT_MAX;

int n = 0, m = 0, k = 0, cnt = -1, hashh = 0;
char arr[siz][siz];
bool visited[siz][siz];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    visited[x][y] = true;
    cnt--;

    if (!cnt)
        return;

    for (int i = 0; i < 4; ++i) {
        int nx , ny;
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1 || arr[nx][ny] != '.')
            continue;
        if (!visited[nx][ny])
            dfs(nx, ny);
        if (!cnt)
            return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '.')
                v.emplace_back(i, j);
            else if (arr[i][j] == '#')
                hashh++;
        }
    }

    cnt = n * m - k - hashh;

    for (auto & i : v) {
        if (arr[i.first][i.second] == '.') {
            dfs(i.first, i.second);
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && arr[i][j] == '.')
                cout << 'X';
            else
                cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}