#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<ll, vector<ll>> arr;
unordered_map<ll, bool> visited;
queue<ll> q;

void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child]) {
            dfs(child);
        }
    }
    q.push(node);
}

int main() {

    ll n, mx = 0;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll u, v;
        cin >> u >> v;
        if (max(u, v) > mx)
            mx = max(u, v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (auto i : arr) {
        if (i.second.size() == 1 && !visited[i.first])
            dfs(i.first);
    }


    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}