#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e6 + 10;
vector<ll> arr[N];
ll mx = 1;
bool visited[N];

ll dfs (ll node) {
    ll num = 0;
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child])
            num += dfs(child);
    }
    num++;
    return num;
}


int main() {
    ll n, m;
    string u, v;
    while(true) {
        mx = 0;;
        unordered_map<string, ll> mapp;
        cin >> n >> m;
        if (!(n || m))
            break;

        for (ll i = 1; i <= N; i++) {
            arr[i].clear();
            visited[i] = false;
        }

        for (ll i = 1; i <= n; i++) {
            cin >> u;
            mapp[u] = i;
        }

        for (ll i = 1; i <= m; i++) {
            cin >> u >> v;
            arr[mapp[v]].push_back(mapp[u]);
            arr[mapp[u]].push_back(mapp[v]);
        }

        cin.ignore();

        for (ll i = 1; i <= n; i++){
            if (!visited[i])
                mx = max(mx, dfs(i));
        }

        cout << mx << endl;
    }
    return 0;
}