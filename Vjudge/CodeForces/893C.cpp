#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 10;

vector<ll> arr[N];
bool visited[N];
ll cost[N];
ll mn;

void dfs(ll node){
    mn = min(cost[node], mn);
    visited[node] = true;
    for(ll child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
}

int main() {
    ll n, m, u, v, mn_cost = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            mn = oo;
            dfs(i);
            mn_cost += mn;
        }
    }

    cout << mn_cost << endl;

    return 0;
}