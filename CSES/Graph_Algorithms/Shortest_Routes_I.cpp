#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e5 + 10;

vector<pair<ll, ll>> arr[N];
ll dis[N];

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
                dis[child.second] = dis[node] + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

int main() {
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, m, u, v, w;
        cin >> n >> m;

        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            dis[i] = oo;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            arr[u].emplace_back(w, v);
        }

        dijkstra(0, 1);

        for (int i = 1; i <= n; ++i)
            cout << dis[i] << ' ';
        cout << endl;
    }

    return 0;
}