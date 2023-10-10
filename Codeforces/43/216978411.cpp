#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t-->0) {
        ll n, m;
        bool xo = false;
        cin >> n >> m;

        if (n%2 && m%2 && n != 1 && m != 1) {
            cout << 1 << '\n';
            cout << n << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
        } else if (((n == 1 && m != 2) || (m == 1 && n != 2)) && !(n == 1 && m == 1)) {
            cout << 1 << '\n';
            if (n == 1)
                cout << 1 << ' ' << m << ' ' << 1 << ' ' << 1 << '\n';
            else
                cout << n << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }

        for (int i = 1; i <= m; ++i)
            cout << 1 << ' ' << i << '\n';
        for (int i = 2; i <= n; ++i)
            cout << i << ' ' << m << '\n';
        if (n%2 == 0 && m%2 && n != 2) {
            for (int i = n; i >= 2; --i) {
                if (!xo) {
                    for (int j = m-1; j >= 1; --j) {
                        cout << i << ' ' << j << '\n';
                    }
                } else {
                    for (int j = 1; j <= m-1; ++j) {
                        cout << i << ' ' << j << '\n';
                    }
                }
                xo ^= true;
            }
        } else {
            for (int i = m - 1; i >= 1; --i) {
                if (!xo) {
                    for (int j = n; j >= 2; --j) {
                        cout << j << ' ' << i << '\n';
                    }
                } else {
                    for (int j = 2; j <= n; ++j) {
                        cout << j << ' ' << i << '\n';
                    }
                }
                xo ^= true;
            }
        }
        cout << 1 << ' ' << 1 << '\n';
    }

    return 0;
}