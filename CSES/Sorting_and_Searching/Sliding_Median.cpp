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
        vector<ll> a(n+1);
        ordered_set<ll> s;

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < k; ++i)
            s.insert(a[i]);

        for (int i = k; i <= n; ++i) {
            auto it = s.find_by_order((k-1)/2);
            cout << *it << ' ';
            s.insert(a[i]);
            s.erase(s.upper_bound(a[i-k]));
        }

        cout << endl;
    }

    return 0;
}