#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 1e3 + 10, inf = INT_MAX;
int mn = inf;

pair<int, int> in[siz];
int out[siz];
vector<vector<int>> res;

int ans, des;

void dfs(int node){
    bool enter = false;
    if(in[node].first != 0) {
        enter = true;
        mn = min(mn, in[node].second);
        dfs(in[node].first);
    }
    des = node;

    if(!enter) {
        vector<int> v;
        v.push_back(ans);
        v.push_back(des);
        v.push_back(mn);
        res.push_back(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v, c;
    cin >> n >> m;

    pair<int, int> p = {0, 0};
    for (int i = 0; i < siz; ++i) {
        in[i] = p;
        out[i] = 0;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> c;
        in[u].first = v;
        in[u].second = c;
        out[v] = u;
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i].first != 0 && out[i] == 0) {
            mn = INT_MAX;
            ans = i;
            dfs(i);
        }
    }

    cout << res.size() << endl;
    for (auto & re : res) cout << re[0] << " " << re[1] << " " << re[2] << endl;
    
    return 0;
}