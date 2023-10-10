#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

vector<pair<ll, ll>> arr[N];
vector<ll> ans;
bool visited[N];

void euler(ll node){
    while(!arr[node].empty()){
        ll child = arr[node].back().first;
        ll edge = arr[node].back().second;
        arr[node].pop_back();
        if (visited[edge])
            continue;
        visited[edge] = true;
        euler(child);
    }
    ans.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    
    while(cin >> n >> m) {
        bool done = false;
        ll u, v;

        for (int i = 0; i < max(n, m); ++i) {
            arr[i].clear();
            visited[i] = false;
        }
        ans.clear();

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            arr[u].emplace_back(v, i);
            arr[v].emplace_back(u, i);
        }

        for (int i = 0; i < n; ++i) {
            if (arr[i].size()%2){
                cout << "Not Possible" << endl;
                done = true;
                break;
            }
        }

        if (done)
            continue;

        for (int i = 0; i < n; ++i) {
            if (!arr[i].empty())
                euler(i);
        }

        if (ans.size() == m+1) {
            cout << "Possible";
        } else
            cout << "Not Possible";
        cout << endl;
    }
    
    return 0;;
}