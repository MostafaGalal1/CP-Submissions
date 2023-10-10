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

    while (t--) {
        ll n, nu;
        cin >> n;
        map<ll, ll> m;

        for (ll i = 0; i < n; ++i)
            cin >> nu, m[nu%3]++;

        ll res = 0;
        ll mn = min(m[1], m[2]);
        res += mn;
        m[1] -= mn;
        m[2] -= mn;

        res += m[0]/2;
        cout << res << endl;
    }

    return 0;
}