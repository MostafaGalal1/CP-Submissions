#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 2e5 + 10, inf = INT_MAX;

int dis[siz], index = 0;
map<int,bool> arr[siz];
vector<int> vv;

void bfs(int node){
    queue<int> q;
    q.push(node);
    index++;
    dis[node] = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        while (arr[node][vv[index]]) {
            if (dis[node] + 1 < dis[vv[index]]) {
                dis[vv[index]] = dis[node] + 1;
                q.push(vv[index]);
            }
            index++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u, v;

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        arr[u][v] = true;
        arr[v][u] = true;
    }

    for (int i = 0; i < n; ++i) {
        cin >> u;
        vv.push_back(u);
    }

    for (int & di : dis) {
        di = inf;
    }

    if (vv[0] == 1) {
        bfs(1);

        if (index == vv.size())
            cout << "Yes";
        else
            cout << "No";
    } else {
        cout << "No";
    }
    cout << endl;

    return 0;
}