#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector g(n, std::vector<std::pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int v, u;
        std::cin >> v >> u;
        --v, --u;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }
    if (n % 3) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> res;
    std::vector ok(n, std::vector<bool>(2, false));
    std::vector<int> sz(n);
    std::vector<bool> exist(n, true);
    auto calc = [&](auto &&calc, int v, int p) -> void {
        sz[v] = 1;
        for (auto [u, id] : g[v]) {
            if (u == p) continue;
            calc(calc, u, v);
            sz[v] += sz[u];
        }
    };
    auto dfs = [&](auto &&dfs, int v, int p) -> void {
        for (auto [u, id] : g[v]) {
            if (u == p) continue;
            if (sz[u] % 3 == 0) {
                exist[id] = false;
                res.emplace_back(id);
                dfs(dfs, u, v);
            } else {
                dfs(dfs, u, v);
            }
        }
    };
    calc(calc, 0, 0);
    dfs(dfs, 0, 0);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (auto [u, id] : g[i]) {
            if (exist[id]) {
                ++cnt;
            }
        }
        if (cnt == 1) {
            ++cnt1;
        } else if (cnt == 2) {
            ++cnt2;
        } else {
            std::cout << -1 << "\n";
            return;
        }
    }
    if (cnt2 != n / 3) {
        std::cout << -1 << "\n";
        return;
    }
    std::cout << (int) res.size() << "\n";
    for (auto x : res) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
 
    while (t--) {
        solve();
    }
}