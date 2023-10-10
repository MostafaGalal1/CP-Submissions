#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll na, nb, nc, sa = 0, sb = 0, sc = 0;
        cin >> na >> nb >> nc;

        vector<ll> a(na), b(nb), c(nc);
        for (ll i = 0; i < na; ++i) cin >> a[i], sa += a[i];
        for (ll i = 0; i < nb; ++i) cin >> b[i], sb += b[i];
        for (ll i = 0; i < nc; ++i) cin >> c[i], sc += c[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        cout << max({sa+sb+sc-2*min({a[0]+b[0], b[0]+c[0], c[0]+a[0]}), sa+sb-sc, sa+sc-sb, sb+sc-sa}) << endl;
    }
    return 0;
}