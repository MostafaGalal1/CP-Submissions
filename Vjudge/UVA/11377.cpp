#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2010, oo = INT_MAX;
vector<ll> arr[N];
map<ll, bool> mapp;
ll dis[N];

void dijkstra (ll node, ll dist){
    queue<pair<ll, ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.front().second;
        dist = -pq.front().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(ll child : arr[node]){
            if (dis[node] + (mapp[child]? 0:1) < dis[child]){
                dis[child] = dis[node] + (mapp[child]? 0:1);
                pq.emplace(-dis[child], child);
            }
        }
    }
}

int main() {
    ll t, tt;
    cin >> t;
    tt = t;

    while (t --> 0) {
        ll n, k, m, u, v, q;
        cin >> n >> m >> k;

        mapp.clear();
        for (int i = 0; i < N; ++i)
            arr[i].clear();

        for (int i = 0; i < k; ++i) {
            cin >> u;
            mapp[u] = true;;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        cin >> q;

        cout << "Case " << tt - t << ":" << endl;
        while (q --> 0) {
            cin >> u >> v;

            for (int i = 0; i < N; ++i)
                dis[i] = oo;

            dijkstra(u, (mapp[u]? 0:1));

            if (u == v){
                cout << 0;
            } else if (dis[v] == oo){
                cout << -1;
            } else {
                cout << dis[v];
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}