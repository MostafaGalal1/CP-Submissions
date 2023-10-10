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
        ll n, k, res = 0, cur = 0;
        cin >> n >> k;
        map<ll, ll> mapp;
        set<ll> s;
        vector<ll> a(n + 1);

        a[0] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i) {
            if (mapp.find(a[i]) != mapp.end()) {
                s.erase(mapp[a[i]]);
            } else {
                if ((ll)mapp.size() >= k) {
                    cur = *s.begin();
                    mapp.erase(a[cur]);
                    s.erase(cur);
                }
            }
            mapp[a[i]] = i, s.insert(i);
            res += cur;
        }

        cout << n*(n+1)/2 - res << endl;
    }

    return 0;
}