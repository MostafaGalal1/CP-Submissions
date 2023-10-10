#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll n;
        cin >> n;
        vector<ll> p(n + 1, 0);
        vector<ll> a(n);
        set<ll> s;

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
            p[a[i]]++;
        }

        for (ll ss : s) {
            res += (ss>1?p[ss - 2]:0) * p[ss - 1] * p[ss];
            res += p[ss - 1] * p[ss] * (p[ss] - 1) / 2;
            res += (ss>1?p[ss - 2]:0) * p[ss] * (p[ss] - 1) / 2;

            res += (ss>1?p[ss - 2]:0) * ((ss>1?p[ss - 2]:0) - 1) / 2 * p[ss];
            res += p[ss - 1] * (p[ss - 1] - 1) / 2 * p[ss];
        }

        for (ll ss : s){
            res += p[ss] * (p[ss] - 1) * max(p[ss] - 2, 0ll) / 6;
        }

        cout << res << endl;
    }

    return 0;
}
