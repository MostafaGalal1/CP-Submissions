#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool reached;
const ll oo = INT_MAX;
const ll N = 1e5 + 10;

ll n;
map<ll, bool> changed;
vector<ll> arr[N];
vector<pair<ll, ll>> edges;
ll dis[N], val[N];
bool visited[N];

void dfs(ll node){
    visited[node] = true;
    if (changed[node]){
        reached = true;
        return;
    }

    for(ll child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
}

void bellford (ll src){
    for (int i = 0; i <= n; ++i)
        dis[i] = oo;

    dis[src] = 0;

    for (ll i = 1; i <= n; i++){
        for (auto & edge : edges){
            ll u = edge.first, v = edge.second, w = val[v];
            if (dis[u] + w < dis[v] && dis[u] + w < 100) {
                if (i == n)
                    changed[v] = true;
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        if (n == -1)
            break;

        reached = false;
        edges.clear();
        changed.clear();
        for (int i = 0; i < N; ++i) {
            arr[i].clear();
            visited[i] = false;
            dis[i] = oo;
            val[i] = 0;;
        }

        ll u, w, c, src = 1;

        for (int i = 1; i <= n; ++i) {
            cin >> w >> c;
            val[i] = -w;
            for (int j = 0; j < c; ++j) {
                cin >> u;
                arr[u].push_back(i);
                edges.emplace_back(i, u);
            }
        }

        bellford(src);

        if (!changed.empty())
            dfs(n);

        cout << (dis[n] < 100 || reached? "winnable":"hopeless") << endl;
    }
    return 0;
}