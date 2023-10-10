#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e6 + 10;
vector<ll> arr[N];
bool visited[N];
ll par[N];

void dfs (ll node) {
    visited[node] = true;

    for (auto child: arr[node]){
        if (!visited[child]) {
            par[child] = node;
            dfs(child);
        }
    }
}

int main() {
    ll n, r1, r2, v;
    cin >> n >> r1 >> r2;

    for (ll i = 1; i <= n; i++) {
        if (i != r1) {
            cin >> v;

            arr[i].push_back(v);
            arr[v].push_back(i);
        }
    }

    dfs(r2);

    for (int i = 1; i <= n; ++i) {
        if(par[i] != 0)
            cout << par[i] << " ";
    }

    cout << endl;

    return 0;
}