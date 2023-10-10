#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 3e4 + 10;
vector<ll> arr[N];
bool visited[N];

ll dfs (ll node) {
    visited[node] = true;
    ll num = 1LL;
    for (auto child : arr[node]){
        if (!visited[child])
            num += dfs(child);
    }
    return num;
}

int main() {
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n, m, mx = 0;
        cin >> n >> m;

        for (int i = 0; i < N; i++) {
            arr[i].clear();
            visited[i] = false;
        }

        for (ll i = 0; i < n; i++)
            visited[i] = false;

        for (ll i = 1; i <= m; i++) {
            ll u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                mx = max(dfs(i), mx);
            }
        }

        cout << mx << endl;
    }
    return 0;
}