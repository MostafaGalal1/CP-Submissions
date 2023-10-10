#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e3 + 10;

vector<pair<ll, ll>> arr[100];
ll dis[100], par[100];

void dijkstra (ll dist, ll flor){
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(-dist, flor);
    dis[flor] = dist;

    while(!pq.empty()){
        flor = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[flor])
            continue;
        for(const auto &i: arr[flor]) {
            if (dis[flor] + i.first < dis[i.second]){
                par[i.second] = flor;
                dis[i.second] = dis[flor] + i.first;
                pq.emplace(-dis[i.second], i.second);
            }
        }
    }
}

int main() {
    ll n, q;

    while (cin >> n >> q) {
        cin.ignore();

        string s;
        int elevtime[n];
        vector<int> acc;

        for (int i = 0; i < 100; ++i) {
            arr[i].clear();
            dis[i] = oo;
            par[i] = -1;
        }

        for (int i = 0; i < n; ++i) {
            cin >> elevtime[i];
        }
        cin.ignore();

        int f;
        for (int i = 0; i < n; ++i) {
            acc.clear();
            getline(cin, s);

            stringstream stream(s);
            while(stream >> f){
                acc.push_back(f);
            }

            for (int k = 0; k < acc.size()-1; ++k) {
                for (int j = k+1; j < acc.size(); ++j) {
                    arr[acc[k]].emplace_back((acc[j]-acc[k])*elevtime[i] + ((acc[j] == q || acc[k] == q)? 0:60), acc[j]);
                    arr[acc[j]].emplace_back((acc[j]-acc[k])*elevtime[i] + ((acc[j] == q || acc[k] == q)? 0:60), acc[k]);;
                }
            }
        }

        dijkstra(0, 0);

        if (par[q] != -1 || q == 0) {
            cout << dis[q] << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}