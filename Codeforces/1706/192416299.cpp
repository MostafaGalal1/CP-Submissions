#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, res = 0;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n%2) {
            for (int i = 1; i < n; i += 2) {
                res += max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0ll);
            }
        } else {
            vector<ll> f(n);
            f[0] = f[n-1] = 0;
            ll cur = 0;
            for (int i = 1; i < n - 1; i++) {
                f[i] += max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0ll);
                if (i % 2)
                    cur += f[i];
            }
            res = cur;

            for (int i = 1; i < n/2; ++i) {
                cur = cur - f[n-1 - i*2] + f[n-1 - i*2 + 1];
                res = min(res, cur);
            }
        }

        cout << res << endl;
    }
    return 0;
}