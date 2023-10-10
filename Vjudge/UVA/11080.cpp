#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 210;

ll pos, neg;
vector<ll> arr[N];
bool visited[N], cyclic = false;
int xorr[N];

void dfs(ll node){
    visited[node] = true;
    if (xorr[node] == 1)
        pos++;
    else
        neg++;
    for (ll child : arr[node]) {
        if (!visited[child]) {
            xorr[child] = xorr[node] == 1? -1:1;
            dfs(child);
        }
        else if (xorr[child] == xorr[node]){
            cyclic = true;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;

    while (t --> 0) {
        pos = neg = 0;
        ll n, m, u, v, res = 0;
        cin >> n >> m;

        cyclic = false;
        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            xorr[i] = 0;
            visited[i] = false;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]){
                xorr[i] = 1;
                pos = 0, neg = 0;
                dfs(i);
                res += max(min(pos, neg), 1ll);
            }
        }

        if (cyclic)
            cout << -1;
        else
            cout << res;
        cout << endl;
    }
    return 0;;
}