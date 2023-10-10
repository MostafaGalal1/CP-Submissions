#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1010;
int n, m;
char a[N][N];
int mapp[N][N];

int rec_dp(int x, int y) {
    if (x == n - 1 && y == m - 1)
        return 1;

    if (x >= n || y >= m || a[x][y] == '#')
        return 0;

    if (~mapp[x][y])
        return mapp[x][y];

    mapp[x+1][y] = rec_dp(x+1, y) % mod;
    mapp[x][y+1] = rec_dp(x, y+1) % mod;

    return (mapp[x+1][y] + mapp[x][y+1]) % mod;
}

int main()
{
    cin >> n >> m;
    memset(mapp, -1, sizeof mapp);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    cout << rec_dp(0, 0) << endl;
    return 0;
}