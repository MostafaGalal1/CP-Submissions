#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 3e4 + 100;

ll n, t;
vector<ll> arr[N];
bool visited[N], found = false;

void dfs(ll node){
    visited[node] = true;
    if (node == t)
        found = true;
    for (ll child : arr[node]){
        if (!visited[child])
            dfs(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll u;
    cin >> n >> t;

    for (int i = 1; i < n; ++i) {
        cin >> u;
        arr[i].push_back(u+i);
    }

    dfs(1);

    if (found)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}