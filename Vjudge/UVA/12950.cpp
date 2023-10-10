#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 7;

vector<pair<ll, ll>> arr[N];
ll dis[N];

void dijkstra (ll node, ll dist){
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        for(auto child : arr[node]){
            for(auto childd : arr[child.second]) {
                if (dis[node] + child.first + childd.first < dis[childd.second]) {
                    dis[childd.second] = dis[node] + child.first + childd.first;
                    pq.emplace(-dis[childd.second], childd.second);
                }
            }
        }
    }
}

int main() {
    ll n, m, u, v, w;
    while (cin >> n >> m) {
        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            dis[i] = oo;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            arr[u].emplace_back(w, v);
            arr[v].emplace_back(w, u);
        }

        dijkstra(1, 0);;

        cout << (dis[n] == oo? -1:dis[n]) << endl;
    }

    return 0;
}