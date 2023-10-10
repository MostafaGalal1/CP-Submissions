#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 10;

int dx[] = {1, 2, -1, 2, 1, -2, -1, -2};
int dy[] = {2, 1, 2, -1, -2, 1, -2 ,-1};

ll dis[8][8];
pair<ll, ll> par[8][8];

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
        for(int i = 0; i < 8; i++) {
            nr = r + dx[i];
            nc = c + dy[i];
            ns = r*nr + c*nc;

            if (nr < 0 || nc < 0 || nr > 7 || nc > 7)
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
    ll srcx, srcy, desx, desy;

    while (cin >> srcx >> srcy >> desx >> desy) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                dis[i][j] = oo;
                par[i][j] = {-1, -1};
            }
        }

        dijkstra(0, srcx, srcy);

        if ((!(par[desx][desy].first == -1 || par[desx][desy].second == -1)) || (srcx == desx && srcy == desy)) {
            cout << dis[desx][desy] << endl;
        } else {
            cout << -1 << endl;;
        }
    }

    return 0;
}