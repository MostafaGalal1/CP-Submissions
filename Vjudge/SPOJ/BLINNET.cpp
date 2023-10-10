#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll par[N];
ll sz[N];

void init(){
    for (ll i = 0; i < N; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

ll fpar(ll j){
    if (j == par[j])
        return j;
    return par[j] = fpar(par[j]);
}

void conn(ll u, ll v){
    u = fpar(u);
    v = fpar(v);
    if (u != v) {
        if (sz[u] >= sz[v])
            par[v] = u, sz[u] += sz[v];
        else
            par[u] = v, sz[v] += sz[u];
    }
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        string s;
        ll n, m, u, v, w, cost = 0;
        cin >> n;

        init();
        vector<pair<ll, pair<ll, ll>>> arr;

        for (ll i = 1; i <= n; ++i) {
            cin >> s;
            cin >> m;
            for (ll j = 0; j < m; ++j) {
                cin >> u >> w;
                arr.push_back({w, {i, u}});
            }
        }

        sort(arr.begin(), arr.end());

        for (auto &i: arr) {
            w = i.first, u = fpar(i.second.first), v = fpar(i.second.second);
            if (fpar(u) == fpar(v)) {
                continue;
            }
            conn(u, v);
            cost += i.first;
        }

        cout << cost << endl;
    }
    return 0;
}