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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].second >> a[i].first;
        }

        sort(a.begin(), a.end());

        ll cnt = 1, mx = a[0].first;
        for (int i = 1; i < n; ++i) {
            if (a[i].second >= mx)
                cnt++, mx = a[i].first;
        }

        cout << cnt << endl;
    }

    return 0;
}