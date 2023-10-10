#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll rem = n, res = 0;

        if (log2(rem) >= k){
            res = (ll)pow(2, k);
        } else {
            while (rem > 0) {
                ll mx = min((ll)log2(rem)+1, k);
                res += (ll) pow(2, mx - 1);
                rem -= (ll) pow(2, mx - 1);
            }
            res++;
        }

        cout << res << endl;
    }

    return 0;
}
