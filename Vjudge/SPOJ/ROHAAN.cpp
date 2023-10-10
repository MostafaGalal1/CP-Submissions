#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 110;

ll n, m;
vector<pair<ll, ll>> arr[N];
ll dis[N];


void dijkstra (ll dist, ll node){
    for (int i = 0; i <= n; ++i)
        dis[i] = oo;

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, tt;
    cin >> t;
    tt = t;

    while (t --> 0) {

        for (int i = 0; i <= n; ++i)
            arr[i].clear();

        ll u, v, w, tot = 0;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> w;
                if (i != j)
                    arr[i].emplace_back(w, j);
            }
        }

        cin >> m;

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            dijkstra(0, u);
            tot += dis[v];
        }

        cout << "Case #" << tt - t << ": " << tot << endl;
    }
    return 0;;
}