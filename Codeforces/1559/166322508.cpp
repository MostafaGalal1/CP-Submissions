#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll par1[N], par2[N];
ll sz1[N], sz2[N];

void init(){
    for (ll i = 0; i < N; ++i) {
        par1[i] = i, par2[i] = i;
        sz1[i] = 1, sz2[i] = 1;
    }
}

ll fpar1(ll j){
    if (j == par1[j])
        return j;
    return par1[j] = fpar1(par1[j]);
}

void conn1(ll u, ll v){
    u = fpar1(u);
    v = fpar1(v);
    if (u != v) {
        if (sz1[u] >= sz1[v])
            par1[v] = u, sz1[u] += sz1[v];
        else
            par1[u] = v, sz1[v] += sz1[u];
    }
}

ll fpar2(ll j){
    if (j == par2[j])
        return j;
    return par2[j] = fpar2(par2[j]);
}

void conn2(ll u, ll v){
    u = fpar2(u);
    v = fpar2(v);
    if (u != v) {
        if (sz2[u] >= sz2[v])
            par2[v] = u, sz2[u] += sz2[v];
        else
            par2[u] = v, sz2[v] += sz2[u];
    }
}

int main() {
    ll t, n, m, u, v, f, g;
    cin >> t >> n >> m;

    init();

    set<pair<ll, ll>> arr;
    map<pair<ll, ll>, bool> arr1;
    map<pair<ll, ll>, bool> arr2;

    for (ll i = 1; i <= n; ++i) {
        cin >> u >> v;
        arr1[{u, v}] = true;
        arr1[{v, u}] = true;
    }

    for (ll i = 1; i <= m; ++i) {
        cin >> u >> v;
        arr2[{u, v}] = true;
        arr2[{v, u}] = true;
    }

    for (int i = 1; i <= t; ++i) {
        for (int j = i+1; j <= t ; ++j) {
            if (!(arr1[{i, j}] || arr2[{i, j}]))
                arr.insert({i, j});
        }
    }

    queue<pair<ll,ll>> q;

    for (auto &i: arr1) {
        if (i.second){
            u = fpar1(i.first.first), v = fpar1(i.first.second);
            if (fpar1(u) == fpar1(v))
                continue;
            conn1(u, v);
        }
    }

    for (auto &i: arr2) {
        if (i.second) {
            u = fpar2(i.first.first), v = fpar2(i.first.second);
            if (fpar2(u) == fpar2(v))
                continue;
            conn2(u, v);
        }
    }

    for (auto &i: arr) {
        u = i.first, v = i.second;
        if (fpar1(u) == fpar1(v) || fpar2(u) == fpar2(v))
            continue;
        q.push({u, v});
        conn1(u, v);
        conn2(u, v);
    }

    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front().first << " " << q.front().second << endl;
        q.pop();
    }

    return 0;
}