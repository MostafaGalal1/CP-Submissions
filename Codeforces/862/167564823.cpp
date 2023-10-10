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
const ll N = 5e5+6, oo = 1e14+7, _oo = -1e16;

int n, m;

ll l1, l2;
vll graph[N];
vll dist;

void bfs(ll node){
    queue<ll> q;
    dist[node] = 0;
    q.push(node);

    while(!q.empty()){
        ll fr = q.front();
        q.pop();
        for(ll adj : graph[fr]){
            if(dist[fr] + 1 < dist[adj]){
                dist[adj] = dist[fr] + 1;
                q.push(adj);
            }
        }
    }
}

void start(){
    cin >> n;
    dist = vector<ll>(n+1, oo);

    for(int i = 1;i < n;i++){
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    for(int i = 1;i <= n;i++){
        if(dist[i]%2) l1++;
        else l2++;
    }
    if(!l1 || !l2) cout << 0 << el;
    else cout << (l1*l2) - (n-1) << el;
}

int main() {
    OB_MASTER
    int tc = 1;
//    cin >> tc;
    while(tc--){
        start();
    }
    return 0;
}