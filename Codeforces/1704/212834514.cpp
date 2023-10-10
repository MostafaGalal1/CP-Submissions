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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
          cin >> a[i];
        }

        ll v = a[0], cnt = 0, mn = 0, mx = 0;
        for (int i = 1; i < n; ++i) {
            if (abs(a[i]-a[i-1]) <= x*2){
                mx = max(mx, a[i]-v);
                mn = min(mn, a[i]-v);
                if (mx - mn > 2*x){
                    cnt++;
                    v = a[i];
                    mn = mx = 0;
                }
            } else {
                cnt++;
                v = a[i];
                mn = mx = 0;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}