#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e4 + 10;
vector<ll> arr[N];
bool visited[N];

void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
}

int main() {
    bool done = false;
    ll n, m;
    cin >> n >> m;

    if (m == n-1) {
        for (ll i = 1; i <= m; i++) {
            ll u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        dfs(1);

        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << "NO";;
                done = true;
                break;
            }
        }

        if(!done)
            cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}