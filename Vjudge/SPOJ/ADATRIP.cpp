#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const int oo = INT_MAX;
const int N = 5e5 + 10;

int n, m, q;
vector<pair<int, int>> arr[N];
int dis[N];

void init(){
    for (int i = 0; i < n; ++i) {
        dis[i] = oo;
    }
}

void dijkstra (int dist, int node){
    priority_queue<pair<int, int>> pq;
    pq.emplace(-dist, node);
    dis[node] = dist;

    while(!pq.empty()){
        node = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (dist > dis[node])
            continue;
        for(auto child : arr[node]){
            if (dis[node] + child.first < dis[child.second]){
                dis[child.second] = dis[node] + child.first;
                pq.emplace(-dis[child.second], child.second);
            }
        }
    }
}

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {

    fast();
    int u, v, c;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        arr[u].emplace_back(c, v);
        arr[v].emplace_back(c, u);
    }

    while (q --> 0) {
        int mx = -1, cnt = 1;
        cin >> u;

        init();
        dijkstra(0, u);

        for (int i = 0; i < n; ++i) {
            if (mx < dis[i] && dis[i] != INT_MAX) {
                cnt = 1;
                mx = dis[i];
            } else if (mx == dis[i]) {
                cnt++;
            }
        }

        cout << mx << " " << cnt << endl;;
    }

    return 0;
}