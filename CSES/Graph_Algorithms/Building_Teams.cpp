#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


bool dfs(ll node, int color, vector<vector<ll>>& a, vector<bool>& vis, vector<int>& col){
    vis[node] = true;
    col[node] = color;
    for (auto & ch : a[node]){
        if (!vis[ch]) {
            if (!dfs(ch, color == 1 ? 2 : 1, a, vis, col))
                return false;
        } else {
            if (color == col[ch])
                return false;
        }
    }
    return true;
}
int main() {
    fast();
    ll n, m, x, y;
    cin >> n >> m;

    vector<ll> res;
    vector<int> col(n+1, 0);
    vector<bool> vis(n+1, false);
    vector<vector<ll>> a(n+1);

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bool can = true;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            can &= dfs(i, 1, a, vis, col);

    if (can){
        for (int i = 1; i <= n; ++i)
           cout << col[i] << ' ';
    } else
        cout << "IMPOSSIBLE";
    cout << endl;

    return 0;
}