#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 1e3 + 10, inf = INT_MAX;

map<int, bool> arr[siz];
bool visited[siz];

void dfs(int node){
    visited[node] = true;
    for (auto & child : arr[node]) {
        if (!visited[child.first])
            dfs(child.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;

    for (bool & i : visited) {
        i = false;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        arr[u][v] = true;
        arr[v][u] = true;
    }

    if (n == m) {
        bool done = false;

        dfs(1);
        for (int i = 1; i <= n; ++i) {
            if(!visited[i]){
                cout << "NO";;
                done = true;
                break;
            }
        }

        if (!done)
            cout << "FHTAGN!";
    } else {
        cout << "NO";
    }
    cout << endl;

    return 0;
}