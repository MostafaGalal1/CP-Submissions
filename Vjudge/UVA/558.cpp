#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 10;

bool neg_cycle;
ll n, m;
vector<pair<ll, pair<ll, ll>>> edges;
ll dis[N];

void bellford (ll src){
    for (int i = 0; i <= n; ++i)
        dis[i] = oo;

    dis[src] = 0;

    for (ll i = 1; i <= n; i++){
        for (auto & edge : edges){
            ll u = edge.second.first, v = edge.second.second, w = edge.first;
            if (dis[u] + w < dis[v]) {
                if (i == n)
                    neg_cycle = true;
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0) {
        ll u, v, w, src = 0;
        cin >> n >> m;

        neg_cycle = false;
        edges.clear();

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }

        bellford(src);

        if (neg_cycle)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;;
    }
    return 0;
}