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
        ll n, m;
        char ch;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));

        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < m; ++j)
                cin >> a[i][j];

        bool done = false;
        string res;
        for (int i = 0; i < n && !done; ++i) {
            string s;
            for (int j = 0; j < m; ++j)
                s += a[i][j];
            res = s;

            for (int j = 0; j < m && !done; ++j) {
                s = res;
                for (int k = 0; k < 26; ++k) {
                    bool pd = false;
                    s[j] = (char)('a'+k);
                    for (int l = 0; l < n && !pd; ++l) {
                        bool d = false;
                        for (int o = 0; o < m; ++o) {
                            if (a[l][o] != s[o]) {
                                if (d) {
                                    pd = true;
                                    break;
                                }
                                d = true;
                            }
                        }
                    }
                    if (!pd) {
                        done = true;
                        res = s;
                        break;
                    }
                }
            }
        }

        if (!done)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}