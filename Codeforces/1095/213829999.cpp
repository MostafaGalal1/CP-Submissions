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
//    cin >> t;
    t = 1;

    while(t --> 0) {
        ll n, m, u, v, w, cost = 0;
        cin >> n >> m;

        init();
        vector<ll> a(n+1);
        vector<pair<ll, pair<ll, ll>>> arr;

        ll mn = LONG_LONG_MAX, mni;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (mn > a[i])
                mn = a[i], mni = i;
        }

        for (int i = 1; i <= n; ++i) {
            if (i == mni)
                continue;
            arr.push_back({a[i]+mn, {i, mni}});
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            arr.push_back({w, {u, v}});
        }

        sort(arr.begin(), arr.end());

        for (ll i = 0; i < (ll)arr.size(); ++i) {
            u = fpar(arr[i].second.first), v = fpar(arr[i].second.second);
            if (fpar(u) == fpar(v))
                continue;
            conn(u, v);
            cost += arr[i].first;
        }

        cout << cost << endl;
    }
    return 0;
}