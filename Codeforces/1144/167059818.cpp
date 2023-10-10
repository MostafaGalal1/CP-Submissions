#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e5 + 10;

vector<ll> arr[N];
vector<pair<ll, ll>> ve;
map<pair<ll, ll>, int> edges;
ll dis[N];
ll n, m;
bool impo;

void init(){
    impo = false;
    edges.clear();
    ve.clear();
    for (int i = 0; i <= n; ++i) {
        arr[i].clear();
        dis[i] = oo;
    }
}

void bfs(ll node, ll xorr){
    queue<pair<ll, ll>> q;
    q.emplace(node, xorr);
    dis[node] = 0;

    while(!q.empty()) {
        node = q.front().first;
        xorr = q.front().second;
        q.pop();

        if (impo)
            return;

        for (ll child : arr[node]) {
            if ((edges[{child, node}] == 1 && xorr) || (edges[{child, node}] == -1 && !xorr)) {
                impo = true;
                return;
            } else {
                if (xorr) {
                    edges[{node, child}] = 1;
                } else {
                    edges[{node, child}] = -1;
                }
            }
            if (dis[node] + 1 < dis[child]) {
                dis[child] = dis[node] + 1;
                q.emplace(child, xorr ^ 1);
            }
        }
    }
}

int main() {
    ll u, v;
    cin >> n >> m;

    init();

    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        ve.emplace_back(u, v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bfs(1, 1);

    if (impo)
        cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i) {
            cout << (edges[{ve[i].first, ve[i].second}] == 1? 1:0);
        }
    }
    cout << endl;

    return 0;
}