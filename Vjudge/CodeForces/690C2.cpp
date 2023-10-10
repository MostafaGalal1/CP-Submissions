#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 1e5+10, inf = INT_MAX;

unordered_map<int, bool> arr[siz];
unordered_map<int, int> dis;

int bfs(int node){
    unordered_map<int, int> empty;
    swap(dis, empty);

    int root = node;
    int num = 0;
    queue<int> q;
    q.emplace(node);
    dis[node] = 0;

    while (!q.empty()){
        node = q.front();
        q.pop();

        for(auto child : arr[node]){
            if (!dis[child.first] && child.first != root) {
                dis[child.first] = dis[node] + 1;
                num = dis[child.first];
                q.push(child.first);
            }
        }
    }

    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        arr[u][v] = true;
        arr[v][u] = true;
    }

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i].size() == 1 && dis[i] == mx)
            mx = max(mx, bfs(i));
    }

    cout << mx << endl;

    return 0;
}