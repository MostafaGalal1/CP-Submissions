#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll siz = 1e6 + 10, inf = LONG_LONG_MAX;

bool visited[siz];
map<ll, bool> arr[siz];
map<pair<ll, ll>, bool> road;
ll br = 0, num = 0, bnum;
queue<ll> q;

void dfs(ll node){
    num++;
    visited[node] = true;

    for (auto child : arr[node]){
        pair<ll, ll> p1 = {node, child.first};
        pair<ll, ll> p2 = {child.first, node};
        if (road[p1] || road[p2]) {
            br = child.first;
            bnum = num;
            road.erase(p1);
            road.erase(p2);
        }
        if (!visited[child.first]) {
            dfs(child.first);
        }
    }

    if (br && bnum == num - 1) {
        q.push(br);
        br = 0;
        bnum = 0;
    }

    num--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, u, v, t;
    cin >> n;

    for (ll i = 0; i < n - 1; ++i) {
        cin >> u >> v >> t;
        pair<ll, ll> p1 = {u, v};
        pair<ll, ll> p2 = {v, u};
        arr[u][v] = true;
        arr[v][u] = true;
        if (t == 1) {
            road[p1] = false;
            road[p2] = false;
        } else {
            road[p1] = true;
            road[p2] = true;
        }
    }

    dfs(1);

    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}