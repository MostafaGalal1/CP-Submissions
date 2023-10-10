#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e5 + 10;

vector<ll> arr[N];
bool visited[N];
ll dis[N];

stack<ll> s;
vector<ll> cycle_vertices;
ll n, num = 0;

bool cyclic = false;
ll root = 0;

void cycle_check(ll node, ll par){
    s.push(node);
    visited[node] = true;;
    for(ll child : arr[node]){
        if (cyclic)
            return;
        if (!visited[child])
            cycle_check(child, node);
        else if (child != par){
            root = child;
            cyclic = true;
            return;
        }
    }
    if (cyclic)
        return;
    s.pop();
}

void dfs(ll node){
    visited[node] = true;
    dis[node] = num++;
    for(ll child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
    num--;
}

int main() {
    ll u, v;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    cycle_check(1, 0);

    for (long long cycle_vertex : cycle_vertices) {
        dfs(cycle_vertex);
    }

    ll sz = (ll)s.size();
    for (int i = 0; i < sz; i++){
        cycle_vertices.push_back(s.top());
        if (s.top() == root)
            break;
        s.pop();
    }

    for (bool & i : visited) {
        i = false;
    }

    for (long long cycle_vertex : cycle_vertices) {
        visited[cycle_vertex] = true;
    }

    for (long long cycle_vertex : cycle_vertices){
        dfs(cycle_vertex);
    }

    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    cout << endl;

    return 0;
}