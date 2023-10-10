#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 8;

ll dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
ll dy[] = {0, 1, 0, -1, 1, -1, -1 ,1};

char arr[2*N][N];
ll dis[2*N][N];
bool reached =false;

void bfs(ll x, ll y){
    queue<pair<ll, ll>> q;
    q.emplace(x, y);
    dis[x][y] = 0;
    ll moves = 0;

    while (!q.empty()){
        ll nx, ny;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        moves = dis[x][y];

        if (x == 8 - min(8ll, moves) && y == 7) {
            reached = true;
            return;
        }

        for (int i = 0; i < 8; ++i) {
            nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 2 * N || ny < 0 || ny >= N || arr[nx][ny] == 'S')
                continue;
            if (nx - 1 >= 0 && arr[nx-1][ny] == 'S')
                continue;
            if (dis[max(0ll, nx - 1)][ny] > dis[x][y] + 1){
                dis[max(0ll, nx - 1)][ny] = dis[x][y] + 1;
                q.emplace(max(0ll, nx - 1), ny);
            }
        }
        for (int i = 8; i < x-1; ++i) {
            if (arr[i][y] == 'S' && arr[x-1][y] != 'S') {
                q.emplace(x - 1, y);
                dis[x - 1][y] = 0;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 2 * N; ++i) {
        for (int j = 0; j < N; ++j) {
            dis[i][j] = oo;
        }
    }

    for (int i = 8; i < 2 * N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    bfs(15, 0);

    if (reached)
        cout << "WIN";
    else
        cout << "LOSE";
    cout << endl;

    return 0;
}