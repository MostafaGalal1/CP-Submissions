#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

ll factorial(ll n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate nCr (combination)
ll nCr(ll n, ll r) {
    ll numerator = factorial(n);
    ll denominator = factorial(r) * factorial(n - r);
    return numerator / denominator;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> a(n), r;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= q)
                cnt++;
            else {
                if (cnt >= k)
                    r.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt >= k)
            r.push_back(cnt);

        ll m = (ll)r.size(), res = 0;
        for (int i = 0; i < m; ++i) {
            ll cur = 1;
            res += r[i] * (r[i] + 1) / 2;
            while (cur < k)
                res -= r[i] - cur++ + 1;
        }

        cout << res << endl;
    }

    return 0;
}
