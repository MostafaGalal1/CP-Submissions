#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll par[26];
ll sz[26];

void init(){
    for (ll i = 0; i < 26; ++i) {
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
    ll n, u, v, cost = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;

    init();

    vector<pair<ll, pair<ll, ll>>> arr;
    queue<pair<ll, ll>> q;

    for (ll i = 0; i < n; ++i) {
        arr.push_back({i, {s1[i] - 'a', s2[i] - 'a'}});
    }

    for (ll i = 0; i < n; ++i) {
        u = arr[i].second.first, v = arr[i].second.second;
        if (fpar(u) == fpar(v))
            continue;
        conn(u, v);
        q.emplace(u, v);
        cost++;
    }

    cout << q.size() << endl;
    char c1, c2;
    while(!q.empty()){
        c1 = q.front().first + 'a', c2 = q.front().second + 'a';
        cout << c1 << " " << c2 << endl;
        q.pop();
    }

    return 0;
}