#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e4 + 10;
vector<ll> arr[N];
bool visited[N];

void dfs (ll node) {
    visited[node] = true;
    for (auto child : arr[node]){
        if (!visited[child]) {
            dfs(child);
        }
    }
}

int main() {

    ll n, count = 0;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll v;
        cin >> v;
        arr[i].push_back(v);
        arr[v].push_back(i);
    }

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    cout << count << endl;

    return 0;
}