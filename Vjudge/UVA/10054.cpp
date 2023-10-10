#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1010;

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

    ll t, tt;
    cin >> t;
    tt = t;
    
    while(t --> 0) {
        bool done = false;
        ll n, u, v;
        cin >> n;

        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            visited[i] = false;
        }
        ans.clear();

        for (int i = 0; i < n; ++i) {
            cin >> u >> v;
            arr[u].emplace_back(v, i);
            arr[v].emplace_back(u, i);
        }

        cout << "Case #" << tt - t << endl;
        for (int i = 1; i <= n; ++i) {
            if (arr[i].size()%2){
                cout << "some beads may be lost" << endl << endl;
                done = true;
                break;
            }
        }

        if (done)
            continue;

        euler(u);

        if (ans.size() == n+1) {
            for (int i = 0; i < n+1; ++i) {
                if (i == 0 || i == n) {
                    cout << ans[i] << " ";
                    continue;
                }
                cout << ans[i] << endl;
                cout << ans[i] << " ";
            }
        } else
            cout << "some beads may be lost";
        cout << endl << endl;
    }
    
    return 0;;
}