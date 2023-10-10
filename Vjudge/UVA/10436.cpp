#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 110;

vector<pair<ll, ll>> arr[N];
ll dis[N], par[N];
map<string, pair<ll, ll>> mapp;
vector<string> names;

void dijkstra (ll dist, ll node){
    priority_queue<pair<ll,ll>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(auto child : arr[node]){
            if (dist + child.first < dis[child.second]){
                par[child.second] = node;
                dis[child.second] = dist + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

int main() {
    ll t, T;
    cin >> t;
    T = t;

    while(t --> 0){
        ll n, m, q, Q, c, w, p;
        string s, u, v;
        cin >> n;

        mapp.clear();
        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            dis[i] = oo;
            par[i] = 0;
        }

        names.clear();
        names.emplace_back("lol");

        for (int i = 1; i <= n; ++i) {
            cin >> s >> c;
            mapp[s] = {i, c};
            names.emplace_back(s);
        }

        cin >> m;

        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            arr[mapp[u].first].emplace_back(w*2 + mapp[v].second, mapp[v].first);
            arr[mapp[v].first].emplace_back(w*2 + mapp[u].second, mapp[u].first);
        }

        cin >> q;
        Q = q;

        cout << "Map #" << T-t << endl;
        while (q --> 0){
            cin >> u >> v >> p;
            cout << "Query #" << Q-q << endl;

            for (int i = 0; i <= n; ++i) {
                dis[i] = oo;
                par[i] = 0;
            }

            dijkstra(mapp[u].second, mapp[u].first);

            ll cur = mapp[v].first, cnt = 0;
            vector<ll> ve;

            while(cur){
                cnt++;
                ve.push_back(cur);
                cur = par[cur];
            }

            for(ll i = cnt - 1; i > 0; i--)
                cout << names[ve[i]] << ' ';
            cout << names[ve[0]] << endl;

            double cost = 1.1 * (double)dis[mapp[v].first] / (double)p;
            cout << "Each passenger has to pay : " << fixed << setprecision(2) << cost << " taka" << endl;
        }

        if (t != 0)
            cout << endl;;
    }

    return 0;
}