#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
vector<ll> arr[N];
map<pair<ll, ll>, int> mapp;
bool xorr = false, visited[N];
ll ind[N];


void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child])
            mapp[{min(node, child), max(node, child)}] = (xorr? 3:2), xorr = !xorr, dfs(child);
    }
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        bool done = false;
        ll n, in, cnt = 0;
        cin >> n;

        xorr = false;
        mapp.clear();

        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            visited[i] = false;
            ind[i] = 0;
        }

        vector<pair<ll, ll>> ve;

        for (ll i = 1; i <= n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
            ve.emplace_back(min(u, v), max(u, v));
            ind[u]++, ind[v]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (ind[i] == 1)
                cnt++, in = i;
            else if (ind[i] > 2)
                cnt += 3;

            if (cnt > 2) {
                done = true;
                break;
            }
        }

        if (done) {
            cout << -1;
        } else {
            dfs(in);
            for (auto & i : ve) {
                cout << mapp[i] << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}