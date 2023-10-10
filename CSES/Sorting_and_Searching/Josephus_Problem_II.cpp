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
        ll n, k;
        cin >> n >> k;
        ordered_set<ll> s;
        for (int i = 1; i <= n; ++i)
            s.insert(i);

        ll i = 0;
        while (!s.empty()) {
            i += k;
            i %= (ll)s.size();
            auto it = s.find_by_order(i);
            cout << *it << ' ';
            s.erase(*it);
        }
        cout << endl;
    }

    return 0;
}