#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, m, k, nu;
        cin >> n >> m >> k;
        vector<ll> a(n);
        multiset<ll> b;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < m; ++i) {
            cin >> nu;
            b.insert(nu);
        }

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            auto it = b.lower_bound(a[i]-k);
            if (it != b.end() && *it <= a[i]+k)
                cnt++, b.erase(it);
        }

        cout << cnt << endl;
    }

    return 0;
}