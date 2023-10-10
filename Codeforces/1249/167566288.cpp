#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define OB_MASTER ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define precision(k) cout.precision(k);
#define F first
#define S second
#define el "\n"
const ll N = 5e6+6, oo = 1e14+7, _oo = -1e16;

int n, m;

vll graph[N];
vector<bool> visited;
vll component, dist;
ll occ;

void dfs(ll node){
    visited[node] = true;
    component.push_back(node);
    for(ll adj : graph[node]){ if(!visited[adj]) dfs(adj); }
}

void start(){
    cin >> n;dist.clear();visited.clear();
    for(int i = 0;i <= n;i++) graph[i].clear();
    visited = vector<bool>(n+1, false);
    dist = vll(n+1, oo);

    for(int i = 1;i <= n;i++){
        ll u;cin >> u;
        graph[i].push_back(u);
    }

    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            component.clear();
            dfs(i);
            for(auto j : component) dist[j] = component.size();
        }
    }
    for(int i = 1;i <= n;i++) cout << dist[i] << " ";cout << el;
}

int main() {
    OB_MASTER
    int tc = 1;
    cin >> tc;
    while(tc--){
        start();
    }
    return 0;
}