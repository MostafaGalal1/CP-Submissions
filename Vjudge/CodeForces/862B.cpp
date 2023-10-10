#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5+10;

ll s1 = 0, s2 = 0;
vector<ll> arr[N];
vector<ll> dis(N, oo);

void bfs(ll node){
    queue<ll> q;
    q.push(node);
    dis[node] = 0;

    while (!q.empty()){
        node = q.front();
        q.pop();

        for(ll child : arr[node]){
            if (dis[child] > dis[node] + 1) {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, u, v;
    cin >> n;

    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i].size() == 1){
            bfs(i);
            break;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dis[i]%2)
            s1++;
        else
            s2++;
    }

    cout << (s1 * s2 == 0? 0:s1*s2-n+1) << endl;

    return 0;
}