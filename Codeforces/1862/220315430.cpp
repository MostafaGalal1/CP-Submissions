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

    while (t--) {
        ll n;
        cin >> n;
        ll m = (ll)sqrtl(2*n)-1;
        ll res = m;
        while (res * (res - 1) / 2 <= n)
            res++;
        res--;
        cout << res + (n - res * (res - 1) / 2) << "\n";
    }

    return 0;
}