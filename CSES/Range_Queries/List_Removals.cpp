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

ll distance (ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t-->0) {
        ll n, nu;
        cin >> n;
        ordered_set<pair<ll, ll>> s;

        for (ll i = 0; i < n; ++i)
            cin >> nu, s.insert({i, nu});

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            auto it = s.find_by_order(nu-1);
            cout << it->second << ' ';
            s.erase(it);
        }
        cout << endl;
    }

    return 0;
}