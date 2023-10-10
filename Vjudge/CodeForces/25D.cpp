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
    ll n, u, v, w, cost = 0;
    cin >> n;

    init();
    map<pair<ll, ll>, bool> mapp;
    vector<pair<ll, pair<ll, ll>>> arr;

    for (ll i = 0; i < n-1; ++i) {
        cin >> u >> v;
        mapp[{u, v}] = true;
        mapp[{v, u}] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n ; ++j) {
            if (mapp[{i, j}] || mapp[{j, i}])
                arr.push_back({0, {i, j}});
            else
                arr.push_back({1, {i, j}});
        }
    }

    sort(arr.begin(), arr.end());;

    queue<pair<ll ,ll>> d;
    queue<pair<ll ,ll>> b;

    for (auto & i : arr) {
        w = i.first, u = fpar(i.second.first), v = fpar(i.second.second);
        if (fpar(u) == fpar(v)) {
            if(w == 0)
                d.push({i.second.first, i.second.second});
            continue;
        }
        if (w == 1)
            b.push({i.second.first, i.second.second});
        conn(u, v);
        cost += i.first;
    }

    cout << d.size() << endl;
    while(!d.empty()){
        cout << d.front().first << " " << d.front().second << " " << b.front().first << " " << b.front().second << endl;
        d.pop();
        b.pop();
    }

    return 0;
}