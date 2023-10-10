#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e5 + 10, oo = INT_MAX;
vector<pair<ll, pair<ll, ll>>> edges;

ll n;
map<ll ,bool> mapp;
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
                    mapp[v] = true;
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    ll t = 1;

    while (cin >> n) {
        ll m, q, u, v, c;;
        ll busy[n + 1];

        edges.clear(), mapp.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> busy[i];
        }

        cin >> m;

        for (long long &di: dis)
            di = oo;

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            c = (ll) pow(busy[v] - busy[u], 3);
            edges.push_back({c, {u, v}});
        }

        bellford(1);

        cin >> q;

        cout << "Set #" << t++ << endl;
        while (q --> 0) {
            cin >> u;
            cout << ((dis[u] < 3 || dis[u] > INT_MAX - 20000 || mapp[u])? "?": to_string(dis[u])) << endl;
        }
    }

    return 0;
}