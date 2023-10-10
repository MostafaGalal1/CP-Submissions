#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i)
                r.push_back(n / i);
        }
    }
    return r;
}

bool dfs(ll u, bool state, map<ll, bool> &mapp, vector<vector<ll>> &adj, vector<bool> &vis) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v])
            return dfs(v, state || mapp[u], mapp, adj, vis);
    }
    return state || mapp[u];
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll a, b;
        cin >> a >> b;

        ll res = max({a, b, 2*min(a, b)});      
        cout << res * res << endl;
    }
    return 0;
}