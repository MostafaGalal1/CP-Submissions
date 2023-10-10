#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e4 + 10;

vector<ll> ans, arr[N];
set<ll> st, z;
ll ind[N];

void dfs(ll node){
    if (!st.count(node)){
        ans.push_back(node);
    }
    for (ll child : arr[node]) {
        ind[child]--;
        if (!ind[child])
            z.insert(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        arr[u].push_back(v);
        ind[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (!ind[i])
            z.insert(i);
    }

    while (!z.empty()) {
        ll node = *z.begin();
        z.erase(node);
        dfs(node);
    }
    if (ans.size() == n){
        for (long long an: ans) {
            cout << an << ' ';;
        }
    } else
            cout << "Sandro fails.";
    cout << endl;

    return 0;
}