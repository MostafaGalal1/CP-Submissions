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
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                vector<ll> d = divis(a[j] - a[i]);
                for (int k = 0; k < (ll)d.size(); ++k) {
                    ld x = 0.5 * ((a[j] - a[i]) * 1.0 / d[k] - d[k]), y = 0.5 * ((a[j] - a[i]) * 1.0 / d[k] + d[k]);
                    if (abs(x - round(x)) < 1e-6 && abs(y - round(y)) < 1e-6) {
                        if ((ll)round(x) * (ll)round(x) - a[i] >= 0)
                            s.insert((ll)round(x) * (ll)round(x) - a[i]);
                        if ((ll)round(y) * (ll)round(y) - a[j] >= 0)
                            s.insert((ll)round(y) * (ll)round(y) - a[j]);
                    }
                }
            }
        }

        ll mx = 1;

        vector<ll> p(s.begin(), s.end());
        for (int i = 0; i < (ll)p.size(); ++i) {
            ll cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((ll)sqrt(p[i]+a[j]) * (ll)sqrt(p[i]+a[j]) == p[i]+a[j])
                    cnt++;
            }
            mx = max(mx, cnt);
        }
        cout << mx << endl;
    }
    return 0;
}