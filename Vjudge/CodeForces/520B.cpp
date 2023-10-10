#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int siz = 2e4 + 10, inf = INT_MAX;

int dis[siz];

void bfs(int node){

    for (int i = 0; i < siz; ++i) {
        dis[i] = inf;
    }

    queue<int> q;
    q.push(node);
    dis[node] = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        if (node * 2 <= siz && dis[node] + 1 < dis[node * 2]){
            dis[node * 2] = dis[node] + 1;
            q.push(node * 2);
        }

        if (node - 1 > 0 && dis[node] + 1 < dis[node - 1]){
            dis[node - 1] = dis[node] + 1;
            q.push(node - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    bfs(n);
    
    cout << dis[m] << endl;

    return 0;;
}