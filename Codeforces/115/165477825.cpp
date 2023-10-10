#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 3e4 + 10;
ll mx = 1, num;
vector<ll> arr[N];
bool visited[N];

void dfs (ll node) {
    visited[node] = true;
    num++;
    for (auto child : arr[node]){
        if (!visited[child]) {
            dfs(child);
            if (num > mx)
                mx = num;
        }
    }
    num--;
}

int main() {

    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll v;
        cin >> v;
        if (v == -1) {
            arr[0].push_back(i);
        } else {
            arr[v].push_back(i);
        }
    }

    for (ll i = 0; i < arr[0].size(); i++) {
            num = 0;
            dfs(i);

    }

    cout << mx << endl;

    return 0;
}