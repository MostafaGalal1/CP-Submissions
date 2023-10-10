#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = INT_MAX;

string s1, s2;
int c1, r1, c2, r2;
int dis[8][8];
int dx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int dy[] = {2, 1, 2, -1, -2, 1, -2 ,-1};

void bfs(int r, int c){

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            dis[i][j] = inf;
        }
    }

    queue<pair<int ,int>> q;
    q.emplace(r, c);
    dis[r][c] = 0;

    while (!q.empty()){
        int nr, nc;
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            nr = r + dx[i];
            nc = c + dy[i];

            if (nr < 0 || nc < 0 || nr > 7 || nc > 7)
                continue;
            if (dis[r][c] + 1 < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + 1;
                q.emplace(nr, nc);
            }
            if (nr == r2 && nc == c2){
                return;
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> s1 >> s2){
        c1 = s1[0] - 'a';
        r1 = s1[1] - '1';
        c2 = s2[0] - 'a';
        r2 = s2[1] - '1';

        bfs(r1, c1);

        cout << "To get from " << s1 << " to " << s2 << " takes " << dis[r2][c2] << " knight moves." << endl;;
    }

    return 0;;
}