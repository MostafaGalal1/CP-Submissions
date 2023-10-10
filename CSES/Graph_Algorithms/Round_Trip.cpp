#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

stack<ll> st;
bool dfs(ll node, ll par, vector<vector<ll>>& a, vector<bool>& vis){
    vis[node] = true;
    st.push(node);
    for (auto & ch : a[node]){
        if (!vis[ch]) {
            if (dfs(ch, node, a, vis))
                return true;
        } else {
            if (ch != par) {
                st.push(ch);
                return true;
            }
        }
    }
    st.pop();
    return false;
}
int main() {
    fast();
    ll n, m, x, y;
    cin >> n >> m;

    vector<bool> vis(n+1, false);
    vector<vector<ll>> a(n+1);

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i, 1, a, vis)) {
            vector<ll> res;
            ll node = st.top();
            res.push_back(node);
            st.pop();
            while (st.top() != node) {
                res.push_back(st.top());
                st.pop();
            }
            res.push_back(node);

            cout << (ll)res.size() << endl;
            for (auto & r : res)
                cout << r << ' ';
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}