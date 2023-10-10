#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e5+10;

vector<ll> arr[N];
bool visited[N];
vector<ll> days(N, 0);
vector<ll> ve;
ll num = 0;

void dfs(ll node){
    visited[node] = true;
    ve.push_back(node);
    num++;
    for (ll child : arr[node]) {
        if (!visited[child])
            dfs(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t --> 0) {
        ll n, u, v;
        cin >> n;

        for (int i = 0; i <= n; ++i) {
            arr[i].clear();
            visited[i] = false;
        }

        ve.clear();

        for (int i = 1; i <= n; ++i) {
            cin >> u;
            arr[i].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                ve.clear();
                num = 0;
                dfs(i);
                for (long long j : ve) {
                    days[j] = num;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << days[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}