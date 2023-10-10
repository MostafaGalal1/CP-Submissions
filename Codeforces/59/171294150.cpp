#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = 1e8;
const ll N = 2e6 + 7, fee = 1e12;


map<pair<ll, pair<ll, ll>>, bool> mapp;
map<ll, ll> routes;
vector<pair<ll, ll>> arr[N];
ll dis[N], par[N], ind[N];

void dijkstra (ll dist, ll node){
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        for(auto child : arr[node]){
            if (routes[child.second] && !mapp[{par[node], {node, child.second}}]){
                pq.emplace(-dis[node] - 1, child.second);
            }
            if (dist + child.first + (mapp[{par[node], {node, child.second}}] && ind[node] < 3? fee:0) + (mapp[{par[node], {node, child.second}}] && ind[node] >= 3? 2:0) + (routes[child.second] && !mapp[{node, {child.second, routes[child.second]}}]? -2:0) < dis[child.second]){
                if (mapp[{par[node], {node, child.second}}] && ind[node] >= 3 && !routes[child.second]) {
                    for (auto & ch : arr[node]){
                        if (ch.second != par[node] && ch.second != child.second){
                            routes[node] = ch.second;
                            break;
                        }
                    }
                } else if (routes[child.second]){
                    routes[child.second] = 0;
                }
                par[child.second] = node;
                dis[child.second] = dis[node] + child.first + (mapp[{par[node], {node, child.second}}] && ind[node] >= 3? 2:0) + (routes[child.second]? -2:0);
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

int main() {
    ll n, m, k, u, v, w;
    cin >> n >> m >> k;

    mapp.clear();
    routes.clear();
    for (int i = 0; i <= n; ++i) {
        arr[i].clear();
        dis[i] = oo;
        par[i] = 0;
        ind[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        arr[u].emplace_back(1, v);
        arr[v].emplace_back(1, u);
        ind[u]++, ind[v]++;
    }

    for (int i = 0; i < k; ++i) {
        cin >> u >> v >> w;
        mapp[{u, {v, w}}] = true;
    }

    dijkstra(0, 1);

    ll cur = n;
    vector<ll> ve;

    if (par[cur] && (m != k)) {
        cout << dis[n] << endl;
        ll length = dis[n];
        while (cur && length) {
            ve.push_back(cur);
            if (routes[cur]){
                ve.push_back(routes[cur]);
                ve.push_back(cur);
                length--;
            }
            cur = par[cur];
            length--;
        }

        if (ve.back() != 1)
            ve.push_back(1);

        reverse(ve.begin(), ve.end());

        for (long long i: ve) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}