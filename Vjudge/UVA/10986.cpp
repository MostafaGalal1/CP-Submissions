#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 10;

vector<pair<ll, ll>> arr[N];
ll dis[N], par[N];

void dijkstra (ll dist, ll node){
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(auto child : arr[node]){
            if (dis[node] + child.first < dis[child.second]){
                par[child.second] = node;
                dis[child.second] = dis[node] + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

int main() {
    ll t, tt;
    cin >> t;
    tt = t;

    while (t --> 0) {
        ll n, m, src, des, u, v, w;
        cin >> n >> m >> src >> des;
        src++, des++;

        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            dis[i] = oo;
            par[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            u++, v++;
            arr[u].emplace_back(w, v);
            arr[v].emplace_back(w, u);
        }

        dijkstra(0, src);

        if (par[des] || src == des) {
            cout << "Case #" << tt - t << ": " << dis[des] << endl;
        } else {
            cout << "Case #" << tt - t << ": unreachable" << endl;
        }
    }

    return 0;;
}