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

bool func (ll k, ll t, vector<ll>& a){
    ll sum = 0;
    for (int i = 0; i < (ll)a.size(); ++i)
        sum += t / a[i];
    return sum >= k;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end());

        ll p = 0, res = 0;
        for (int i = 0; i < n; ++i)
            p += a[i].first, res += a[i].second - p;
        cout << res << endl;
    }

    return 0;
}