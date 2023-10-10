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
        vector<ll> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        ll mx = LONG_MIN, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = max(a[i], sum+a[i]);
            mx = max(mx, sum);
        }

        cout << mx << endl;
    }

    return 0;
}