#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

vector<pair<ll, ll>> arr[N];
ll k, cnt = 0, dis[N];
map<pair<ll, ll>, ll> mapp;

void dijkstra (ll dist, ll node){
    priority_queue<pair<ll,ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(auto child : arr[node]){
            if (dist + child.first < dis[child.second]){
                dis[child.second] = dist + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

int main() {
    ll n, m, s, u, v, w;
    cin >> n >> m >> s;

    for (int i = 0; i <= n; ++i) {
        arr[i].clear();
        dis[i] = oo;
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        arr[u].emplace_back(w, v);
        arr[v].emplace_back(w, u);
        mapp[{u, v}] = w;
    }

    cin >> k;

    dijkstra(0, s);

    for (int i = 1; i <= n; ++i) {
        if (dis[i] == k)
            cnt++;
    }

    for (auto & i : mapp) {
        if (i.second + dis[i.first.first] > k && dis[i.first.first] < k && dis[i.first.first] + dis[i.first.second] + i.second > 2*k)
            cnt++;
        if (i.second + dis[i.first.second] > k && dis[i.first.second] < k && dis[i.first.first] + dis[i.first.second] + i.second > 2*k)
            cnt++;
        if (dis[i.first.first] < k && dis[i.first.second] < k && dis[i.first.first] + dis[i.first.second] + i.second == 2*k)
            cnt++;

    }

    cout << cnt << endl;

    return 0;
}