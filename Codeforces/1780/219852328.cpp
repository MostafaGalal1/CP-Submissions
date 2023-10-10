#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 1; i < n; ++i)
            a[i] += a[i - 1];

        ll res = 1;
        for (int i = n-2; i >= 0; --i)
            res = max(res, __gcd(a[i], a[n-1] - a[i]));

        cout << res << endl;
    }
    return 0;
}