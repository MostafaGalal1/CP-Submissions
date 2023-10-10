#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 5e5 + 10;

vector<ll> arr[N];
map<ll, bool> mapp;
ll dis[N];
ll n, m;

void init(){
    mapp.clear();
    for (int i = 0; i <= n; ++i) {
        arr[i].clear();
        dis[i] = oo;
    }
}

void bfs(ll node, ll xorr){
    queue<pair<ll, ll>> q;
    q.emplace(node, xorr);
    dis[node] = 0;

    while(q.size()) {
        node = q.front().first;
        xorr = q.front().second;
        q.pop();

        if (xorr)
            mapp[node] = true;

        for (ll child : arr[node]) {
            if (dis[node] + 1 < dis[child]) {
                dis[child] = dis[node] + 1;
                q.emplace(child, xorr^1);
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;

    while(t --> 0) {
        ll u, v;
        cin >> n >> m;

        init();

        for (ll i = 0; i < m; ++i) {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        ll mx = 0, index = 0;
        for (ll i = 1; i <= n; ++i) {
            if ((ll)arr[i].size() > mx) {
                mx = (ll)arr[i].size();
                index = i;
            }
        }

        bfs(index, 1);

        if (mapp.size() <= n/2) {
            cout << mapp.size() << endl;
            for (auto &i : mapp)
                cout << i.first << ' ';
        } else {
            cout << n - mapp.size() << endl;
            for (ll i = 1; i <= n; ++i) {
                if (mapp[i])
                    continue;
                cout << i << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}