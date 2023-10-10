#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool flag = false;

const ll N = 1e6 + 10;
vector<ll> arr[N];
vector<int> color(N, 0);
bool visited[N];

void isBipartite(ll u){
    for(auto child : arr[u]){
        if(!visited[child]){
            visited[child] = true;
            color[child] = !color[u];
            isBipartite(child);
        } else if (color[child] == color[u]){
            flag = true;
        }
    }
}

int main() {
    ll t;
    cin >> t;

    for (ll h = 1; h <= t; h++) {
        flag = false;
        ll n, m, u, v;
        cin >> n >> m;

        vector<int> empty(N, -1);
        swap(color, empty);
        
        for (ll i = 0; i < N; i++) {
            arr[i].clear();
            visited[i] = false;
        }

        for (ll i = 1; i <= m; i++) {
            cin >> u >> v;
            arr[v].push_back(u);
            arr[u].push_back(v);
        }

        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                isBipartite(i);
            }
        }

        cout << "Scenario #" << h << ":" << endl;
        if (flag) {
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }
    }
    return 0;
}