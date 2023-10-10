#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, m, d, nu, val;
        cin >> n >> m >> d;

        set<ll> s;
        s.insert(1-d);
        for (ll i = 0; i < m; ++i) {
            cin >> nu;
            s.insert(nu);
        }

        vector<ll> a(s.begin(), s.end());
        a.push_back(n+1);
        ll res = 0;
        for (int i = 1; i < (ll)a.size(); ++i)
            res += (a[i] - a[i-1] - 1) / d + 1;

        ll mn = LONG_LONG_MAX, cnt;
        for (int i = 1; i < (ll)a.size()-1; ++i) {
            val = res - 1 + ((a[i+1] - a[i-1] - 1) / d) - ((a[i] - a[i-1] - 1) / d) - ((a[i+1] - a[i] - 1) / d);
            if (val < mn)
                mn = val, cnt = 1;
            else if (val == mn)
                cnt++;
        }

        cout << mn-1 << ' ' << cnt << endl;
    }
    return 0;
}