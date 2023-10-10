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

    while(t --> 0) {
        ll n, m, k, u, v, w, cost = 0, diff = LONG_LONG_MAX;
        cin >> n >> m >> k;

        init();

        vector<pair<ll, pair<ll, ll>>> arr;

        for (ll i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            arr.push_back({max(0ll, w - k), {u, v}});
            if (diff > abs(w - k)) {
                diff = abs(w - k);
            }
        }

        sort(arr.begin(), arr.end());

        for (ll i = 0; i < m; ++i) {
            u = fpar(arr[i].second.first), v = fpar(arr[i].second.second);
            if (fpar(u) == fpar(v))
                continue;
            conn(u, v);
            cost += arr[i].first;
        }

        cout << (cost ? cost : diff) << endl;
    }
    return 0;
}