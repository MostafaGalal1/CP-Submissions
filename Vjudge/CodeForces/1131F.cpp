#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll n, par[N], sz[N];
map<ll, vector<ll>> sets;

void init(){
    for (ll i = 1; i <= n; ++i) {
        sets[i].push_back(i);
        par[i] = i;
        sz[i] = 1;
    }
}

ll findPar(ll j){
    if (j == par[j])
        return j;
    return par[j] = findPar(par[j]);
}

void Union(ll u, ll v){
    u = findPar(u);
    v = findPar(v);
    if (u != v) {
        if (sz[v] > sz[u]) {
            par[u] = v, sz[v] += sz[u];
            for (int i = 0; i < sets[u].size(); ++i)
                sets[v].push_back(sets[u][i]);
            sets.erase(u);
        } else {
            par[v] = u, sz[u] += sz[v];
            for (int i = 0; i < sets[v].size(); ++i)
                sets[u].push_back(sets[v][i]);
            sets.erase(v);
        }
    }
}

int main() {
    ll u, v;
    cin >> n;

    init();

    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        Union(u, v);
    }

    for (ll j : sets[findPar(1)])
        cout << j << ' ';

    cout << endl;

    return 0;
}