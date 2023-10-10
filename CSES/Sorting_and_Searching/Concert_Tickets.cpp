#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, m, nu, mu;
        cin >> n >> m;
        multiset<ll> a;

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            a.insert(nu);
        }

        for (int i = 0; i < m; ++i) {
            cin >> mu;
            auto it = a.lower_bound(mu);
            if (*it == mu) {
                cout << mu << endl;
                a.erase(it);
            } else if (it != a.begin()) {
                cout << *prev(it) << endl;
                a.erase(prev(it));
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}