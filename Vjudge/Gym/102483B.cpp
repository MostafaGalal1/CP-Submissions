#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int oo = 1e6+9;
vector<int> adj[oo];
int val[oo];
int deg[oo];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            v--;
            adj[i].push_back(v);
            deg[v]++;
        }
    }

    int ans = -1;
    set<pair<int, int>> st;
    for(int i = 0; i < n; ++i) {
        if (deg[i] == 0)
            st.insert({val[i], i});
    }

    int rmv = n-1;
    while(!st.empty()){
        auto tmp = *st.begin();
        int v = tmp.first;
        int x = tmp.second;
        st.erase(st.begin());
        ans = max(ans, v + rmv + deg[x]);
        rmv--;

        for (auto u : adj[x]) {
            deg[u]--;
            if (deg[u] == 0)
                st.insert({val[u], u});
        }
    }
    cout << ans << endl;
    return 0;
}