#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 1e4 + 10;

ll cnt = 0;
map<ll, vector<pair<ll, ll>>> arr;
map<ll, bool> visited;
map<pair<ll, ll>, vector<ll>> mapp;
vector<ll> ans;

void euler(ll node){
    while(!arr[node].empty()){
        ll child = arr[node].back().second;
        ll ind = arr[node].back().first;
        arr[node].pop_back();
        if (visited[ind])
            continue;
        visited[ind] = true;
        euler(child);
    }
    ans.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        bool done = false, first = true;
        ll m = 0, u, v, w, src = LONG_LONG_MAX;

        arr.clear(), visited.clear(), ans.clear(), mapp.clear();

        while (true) {
            cin >> u >> v;
            if (!u && !v) {
                cnt++;
                break;
            }
            cnt = 0;
            cin >> w;
            m++;
            if (first){
                src = min(u, v);
                first = false;
            }
            arr[u].emplace_back(w, v);
            arr[v].emplace_back(w, u);
            mapp[{min(u,v), max(u,v)}].push_back(w);
        }

        if (cnt == 2)
            return 0;

        for (auto &child: arr) {
            sort(child.second.rbegin(), child.second.rend());
            arr[child.first] = child.second;
            if (child.second.size()%2) {
                cout << "Round trip does not exist." << endl << endl;
                done = true;
                break;
            }
        }

        if (done)
            continue;

        for (auto &child: mapp) {
            sort(child.second.rbegin(), child.second.rend());
            mapp[child.first] = child.second;
        }

        euler(src);
        if (ans.size() == m+1) {
            for (int i = m; i > 0; --i) {
                cout << mapp[{min(ans[i], ans[i-1]), max(ans[i], ans[i-1])}].back();
                mapp[{min(ans[i], ans[i-1]), max(ans[i], ans[i-1])}].pop_back();
                if (i != 1)
                    cout << ' ';
            }
        } else
            cout << "Round trip does not exist.";

        cout << endl << endl;;
    }
}