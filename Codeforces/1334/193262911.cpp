#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main() {
    fast();

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        ll sum = a[0], mn = LONG_LONG_MAX;
        for (int i = 0; i < n-1; ++i) {
            a[i+1] -= b[i];
            sum += max(0ll, a[i+1]);
        }

        for (int i = 1; i < n+1; ++i) {
            sum -= max(0ll, a[i%n]) + a[i-1];
            a[i%n] += b[i-1];
            a[i-1] -= b[(i-2+n)%n];
            sum += max(a[i-1], 0ll) + a[i%n];
            mn = min(mn, sum);
        }

        cout << mn << endl;
    }

    return 0;
}