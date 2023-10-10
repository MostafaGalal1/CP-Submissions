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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n+1);

        a[0] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i)
            a[i] += a[i-1];

        ll cnt = 0;
        for (int i = 1; i <= n; ++i) {
            auto it = lower_bound(a.begin(), i+a.begin(), a[i]-x);
            if (*it + x == a[i])
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}