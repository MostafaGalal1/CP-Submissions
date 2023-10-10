#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;

ll cnt = 0, lvl = 0;
vector<ll> arr[N];
bool visited[N], vis[N];
vector<ll> ve[N];
vector<pair<ll, ll>> sor;

void exp (ll node) {
    vis[node] = true;
    sor.push_back({lvl, node});
    for (auto child : arr[node]){
        if (!vis[child])
            lvl++, exp(child);
    }
    lvl--;
}

bool dfs (ll node) {
    bool leaf = true;
    visited[node] = true;
    ve[cnt].push_back(node);
    for (auto child : arr[node]){
        if (!visited[child]) {
            leaf = false;
            if (dfs(child)) {
                return true;
            }
        }
    }
    if (leaf)
        return true;
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, u, root = 1;
        cin >> n;

        cnt = 0, lvl = 0;
        sor.clear();
        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            ve[i].clear();
            vis[i] = false;
            visited[i] = false;
        }

        for (int i = 1; i <= n; ++i) {
            cin >> u;
            if (i == u) {
                root = i;
                continue;
            }
            arr[u].push_back(i);
            arr[i].push_back(u);
        }

        exp(root);
        sort(sor.begin(), sor.end());

        for (ll i = 0; i < n; i++) {
            if (!visited[sor[i].second]) {
                dfs(sor[i].second);
                cnt++;
            }
        }

        cout << cnt << endl;
        for (int i = 0; i < cnt; ++i) {
            cout << (ll)ve[i].size() << endl;
            for (int j = 0; j < (ll)ve[i].size(); ++j) {
                cout << ve[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}