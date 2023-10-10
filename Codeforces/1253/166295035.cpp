#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll max_node = 0;
vector<ll> arr[N];
bool visited[N];
ll par[N];
ll sz[N];

void init(){
    for (ll i = 0; i < N; ++i) {
        arr[i].clear();
        visited[i] = false;
        par[i] = i;
        sz[i] = 1;
    }
}

ll fpar(ll j){
    if (j == par[j])
        return j;
    return par[j] = fpar(par[j]);
}

void conn(ll u, ll v){
    u = fpar(u);
    v = fpar(v);
    if (u != v) {
        if (sz[u] >= sz[v])
            par[v] = u, sz[u] += sz[v], sz[v] = 0;
        else
            par[u] = v, sz[v] += sz[u], sz[u] = 0;
    }
}

void dfs(ll node){
    max_node = max(max_node, node);
    visited[node] = true;
    for (auto & child : arr[node])
        if (!visited[child])
            dfs(child);
}

int main() {
    ll n, m, u, v, cost = 0;
    cin >> n >> m;

    init();

    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        conn(u, v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    ll j = 1;
    while (j <= n){
        dfs(j);
        ll curpar = fpar(j);

        for (ll i = j + 1; i <= max_node; ++i) {
            if (fpar(i) != curpar) {
                conn(par[i], curpar);
                dfs(i);
                curpar = sz[par[i]] >= sz[curpar] ? par[i] : curpar;
                cost++;
            }
        }

        j = max_node + 1;
    }

    cout << cost << endl;

    return 0;
}