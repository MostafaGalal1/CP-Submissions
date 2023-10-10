#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 30, inf = INT_MAX;

int n = 1, m = 1;

bool arr[siz][siz];
bool visited[siz][siz];

int dx[] = {1, 0, -1, 0,1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

int dfs(int x, int y){
    int num = 1;
    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m)
            continue;
        if (!visited[nx][ny])
            num += dfs(nx, ny);
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while(t --> 0) {
        int mx = 0;
        string s;

        for (int i = 0; i < siz; ++i) {
            for (int j = 0; j < siz; ++j) {
                arr[i][j] = false;
                visited[i][j] = false;
            }
        }

        int u = 1;
        while (u <= m){
            cin >> s;
            m = (int)s.length();
            for (int j = 1; j <= m; ++j) {
                if (s[j-1] == '1')
                    arr[u][j] = true;
                else {
                    arr[u][j] = false;
                    visited[u][j] = true;
                }
            }
            u++;
        }

        n = m;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!visited[i][j]) {
                    mx = max(mx, dfs(i, j));
                }
            }
        }

        cout << mx << endl;
        if (t)
            cout << endl;
    }
    return 0;;
}