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
    bool flag = false;
    ll n, m, k, w, u, v, cost = 0;
    cin >> n >> m;

    init();

    vector<pair<ll, pair<ll, ll>>> arr;
    set<ll> lang;

    for (ll i = 1; i <= n; ++i) {
        cin >> k;
        if (k)
            flag = true;
        for (int j = 0; j < k; ++j) {
            cin >> u;
            arr.push_back({0, {i, n + u}});
            lang.insert(n + u);
        }
    }

    if (!flag){
        lang.insert(n + 1);
    }

    for (auto i : lang) {
        for (int j = 1; j <= n; ++j) {
            arr.push_back({1, {j, i}});
        }
    }

    sort(arr.begin(), arr.end());

    for (ll i = 0; i < arr.size(); ++i) {
        w = arr[i].first, u = arr[i].second.first, v = arr[i].second.second;
        if (fpar(u) == fpar(v))
            continue;
        conn(par[u], par[v]);
        cost += w;
    }

    cout << cost << endl;

    return 0;
}