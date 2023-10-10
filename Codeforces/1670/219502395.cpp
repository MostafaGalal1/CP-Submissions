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
        ll n, nu;
        cin >> n;
        vector<bool> vis(n + 1, false);
        map<ll, bool> mapp;
        vector<ll> a(n);
        vector<vector<ll>> adj(n + 1);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            if (a[i] != nu)
                adj[a[i]].push_back(nu);
            else
                vis[a[i]] = true;
        }

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            mapp[nu] = true;
        }

        ll cnt = 1;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i])
                cnt = mul(dfs(i, false, mapp, adj, vis)?1:2, cnt);
        }
        cout << cnt << endl;
    }
    return 0;
}