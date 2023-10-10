#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

int num = 0;
unordered_map<int, vector<int>> arr;
unordered_map<int, bool> visited;
unordered_map<int, bool> selves;

void dfs(int node){
    visited[node] = true;
    num++;
    for (int child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    int u, v;
    ll self = 0, cnt = 0;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (u == v) {
            self++;
            selves[u] = true;
            continue;
        }
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(v);

    int ind = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i].empty()) {
            ind++;
            if (selves[i]) {
                num = 0;
                break;
            }
        }
        cnt += (ll) arr[i].size() * ((ll) arr[i].size() - 1) / 2;
    }

    cnt += self * m - self * (self + 1) / 2;

    cout << (num == n-ind? cnt:0) << endl;
}