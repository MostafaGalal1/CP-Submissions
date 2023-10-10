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
    cin >> t;
//    t = 1;

    while (t--) {
        ll n, d, h;
        cin >> n >> d >> h;
        vector<ll> a(n);

        ld du = 0.5 * d / h;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        ld res = 0;
        ld dh = du * h * h;
        for (int i = 1; i < n; ++i) {
            ll k = h-(a[i]-a[i-1]);
            res += a[i] - a[i - 1]<h?dh - du*k*k:dh;
        }
        res += dh;

        cout << setprecision(16) << res << endl;
    }

    return 0;
}