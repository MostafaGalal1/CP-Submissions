#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e5+10, oo = LONG_LONG_MAX;
vector<pair<ll, ll>> arr[N];
vector<ll> t[N];
ll dis[N], ind[N];


void dijkstra (ll dist, ll node){
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;
    ind[node] = 1;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(auto child : arr[node]){
            if (dis[node] + child.first < dis[child.second]){
                ind[child.second] = 1;
                dis[child.second] = dis[node] + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
            else if (dis[node] + child.first == dis[child.second]){
                ind[child.second]++;
            }
        }
    }
}

int main() {
    ll n, k, m, u, v, w, cnt = 0;
    cin >> n >> m >> k;

    for (long long & di : dis) {
        di = oo;
    }

    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        arr[u].emplace_back(w, v);
        arr[v].emplace_back(w, u);
    }

    for (ll i = 0; i < k; ++i) {
        cin >> u >> w;
        t[u].push_back(w);
        arr[1].emplace_back(w, u);
        arr[u].emplace_back(w, 1);
    }

    dijkstra(0, 1);

    for (int i = 1; i <= n; i ++ ) {
        for (ll we : t[i]) {
            if (we > dis[i])
                cnt++;
            if (we == dis[i] && ind[i] > 1)
                cnt++, ind[i]--;
        }
    }

    cout << cnt << endl;

    return 0;
}