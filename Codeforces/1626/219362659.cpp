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
        string s;
        cin >> s;
        ll n = (ll)s.size();

        ll mxi = 0;
        for (int i = 0; i < n-1; ++i) {
            if (s[i] - '0' + s[i+1] - '0' >= 10)
                mxi = i;
        }
        cout << s.substr(0, mxi) << (s[mxi] - '0' + s[mxi+1] - '0') << s.substr(mxi+2) << endl;
    }
    return 0;
}