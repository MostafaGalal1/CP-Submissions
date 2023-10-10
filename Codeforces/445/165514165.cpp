#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 3e4 + 10;
ll num;
vector<ll> arr[N];
bool visited[N];

void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child]) {
            num++;
            dfs(child);
        }
    }
}

int main() {

    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if(!visited[i])
            dfs(i);
    }

    cout << (ll)pow(2, num) << endl;

    return 0;
}