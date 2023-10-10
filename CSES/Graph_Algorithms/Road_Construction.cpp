#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

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
            par[v] = u, sz[u] += sz[v], sz[v] = 0;
        else
            par[u] = v, sz[v] += sz[u], sz[u] = 0;
    }
}

int main() {
    fast();
    ll n, m, x, y, u, v;
    cin >> n >> m;

    init();

    ll cnt = n, mx = 1;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        u = fpar(x), v = fpar(y);
        if (fpar(u) == fpar(v)) {
            cout << cnt << ' ' << mx << endl;
            continue;
        }
        mx = max(mx, sz[u] + sz[v]);
        conn(u, v);
        cout << --cnt << ' ' << mx << endl;
    }

    return 0;
}