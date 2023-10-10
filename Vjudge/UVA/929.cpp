#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e3 + 10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll n, m;
ll dis[N][N], arr[N][N];
pair<ll, ll> par[N][N];

void dijkstra (ll dist, ll r, ll c){
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    pq.push({-dist, {r, c}});
    dis[r][c] = dist;

    while(!pq.empty()){
        ll nr, nc, ns;
        r = pq.top().second.first;
        c = pq.top().second.second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[r][c])
            continue;
        for(int i = 0; i < 4; i++) {
            nr = r + dx[i];
            nc = c + dy[i];
            ns = arr[r][c];

            if (nr < 0 || nc < 0 || nr > n-1 || nc > m-1)
                continue;
            if (dis[r][c] + ns < dis[nr][nc]){
                par[nr][nc] = {r, c};
                dis[nr][nc] = dis[r][c] + ns;
                pq.push({-dis[nr][nc], {nr, nc}});
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                dis[i][j] = oo;
                par[i][j] = {-1, -1};
            }
        }

        dijkstra(0, 0, 0);;

        cout << dis[n-1][m-1] + arr[n-1][m-1] << endl;
    }

    return 0;
}