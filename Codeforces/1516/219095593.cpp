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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n-1 && k; ++i) {
            if (k >= a[i]){
                a[n-1] += a[i];
                k -= a[i];
                a[i] = 0;
            } else {
                a[n-1] += k;
                a[i] -= k;
                k = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}