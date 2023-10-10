#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e4 + 10;
vector<ll> arr[N];
bool visited[N];

int n, cnt = 0;
string s;

pair<int, int> dfs (ll node) {
    int w = 0 , b = 0;
    visited[node] = true;
    pair<int, int> p;
    for (auto child : arr[node]){
        if (!visited[child]) {
            p = dfs(child);
            w += p.first, b += p.second;
        }
    }

    if (s[node - 1] == 'W')
        w++;
    else
        b++;

    if (w == b)
        cnt++;

    return {w, b};
}

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int u;
        cnt = 0;
        for (int i = 0; i < N; ++i) {
            arr[i].clear();
            visited[i] = false;
        }

        cin >> n;

        for (ll i = 2; i <= n; i++) {
            cin >> u;
            arr[i].push_back(u);
            arr[u].push_back(i);
        }

        cin >> s;
        dfs(1);

        cout << cnt << endl;
    }
}