#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i)
                r.push_back(n / i);
        }
    }
    return r;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, ne = 0;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < 0)
                ne++;
        }

        for (int i = 0; i < n; ++i) {
            if (ne)
                a[i] = -abs(a[i]), ne--;
            else
                a[i] = abs(a[i]);
        }

        vector<ll> b = a;
        sort(b.begin(), b.end());

        if (a == b)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}