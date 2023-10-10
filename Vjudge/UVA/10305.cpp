#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 110;
vector<ll> arr[N];
bool visited[N];
queue<ll> q;

void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
    q.push(node);
}

int main() {
    ll n = 1, m = 1,u , v;
    while(true) {
        cin >> n >> m;
        if (!(n || m))
            break;

        for (ll i = 0; i < N; i++) {
            arr[i].clear();
            visited[i] = false;
        }

        for (ll i = 1; i <= m; i++) {
            cin >> u >> v;
            arr[v].push_back(u);
        }

        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}