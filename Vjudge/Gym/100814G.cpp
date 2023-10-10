#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 2e5 + 10;

ll n, m, k;
vector<pair<pair<ll,ll>, ll>> arr[N];
ll dis[N];

void dijkstra (ll dist, ll node, ll wis){
    priority_queue<pair<ll, ll>> pq;
    pq.push({-dist, node});
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        pq.pop();

        for(auto child : arr[node]){
            if (dis[node] + child.first.second < dis[child.second] && child.first.first <= wis){
                dis[child.second] = dis[node] + child.first.second;
                pq.push({-dis[child.second], child.second});
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll u, v, c, w;
        cin >> n >> m >> k;

        for (int i = 0; i < N; ++i)
            arr[i].clear();

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> c >> w;
            arr[u].push_back({{w, c}, v});
            arr[v].push_back({{w, c}, u});
        }

        ll l = 0, r = 1e9 + 5, md, res = -1;
        while (l <= r) {
            md = (l + r) / 2;
            for (int i = 0; i <= n; ++i)
                dis[i] = oo;
            dijkstra(0, 1, md);
            if (dis[n] < k) {
                res = md;
                r = md - 1;
            } else {
                l = md + 1;;
            }
        }

        cout << res << endl;
    }

    return 0;
}