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
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n-1; ++i) {
            a[i+1] ^= a[i];
        }

        bool done = false;
        for (int i = 0; i < n-1 && !done; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((a[i] == (a[n-1] ^ a[j-1]) && j-1 == i) || (a[i] == (a[n-1] ^ a[j-1]) && a[i] == (a[j-1] ^ a[i]))){
                    done = true;
                    break;
                }
            }
        }

        if (done)
           cout << "YES";
        else
           cout << "NO";
        cout << endl;
    }
    return 0;
}