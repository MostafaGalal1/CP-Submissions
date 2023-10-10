#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


void dfs(ll node, vector<vector<ll>>& a, vector<bool>& vis){
    vis[node] = true;
    for (auto & ch : a[node]){
        if (!vis[ch])
            dfs(ch, a, vis);
    }
}
int main() {
    fast();
    ll n, m, x, y, node;
    cin >> n >> m;

    queue<ll> q;
    vector<ll> dis(n+1, LONG_LONG_MAX), par(n+1, 0), res;
    vector<vector<ll>> a(n+1);

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    q.push(1);
    dis[1] = 0;
    while (!q.empty()){
        node = q.front();
        q.pop();
        for (auto & ch : a[node]){
            if (dis[node] + 1 < dis[ch]){
                dis[ch] = dis[node] + 1;
                par[ch] = node;
                q.push(ch);
            }
        }
    }

    if (dis[n] == LONG_LONG_MAX)
        cout << "IMPOSSIBLE";
    else {
        ll cur = n;
        while (cur){
            res.push_back(cur);
            cur = par[cur];
        }
        reverse(res.begin(), res.end());

        cout << (ll)res.size() << endl;
        for (long long re : res)
            cout << re << ' ';
    }
    cout << endl;

    return 0;
}