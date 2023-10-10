#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e5 + 10;
vector<ll> arr[N];
queue<ll> q;

bool visited[N];
bool init[N];
bool goal[N];

void dfs (ll node, bool xo1, bool xo2) {
    visited[node] = true;
    if ((init[node] ^ goal[node]) ^ xo1){
        q.push(node);
        xo1 ^= true;
    }
    for (auto child : arr[node]){
        if (!visited[child]) {
            dfs(child, xo2, xo1);
        }
    }
}

int main() {

    ll n;
    cin >> n;

    for (ll i = 1; i <= n-1; i++) {
        ll u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        cin >> init[i];
    }

    for (ll i = 1; i <= n; i++) {
        cin >> goal[i];
    }

    dfs(1, false, false);

    cout << q.size() << endl;
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
