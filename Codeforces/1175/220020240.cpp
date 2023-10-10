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
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n-1; ++i)
            a[n-i-2] += a[n-i-1];

        ll res = a[0];
        sort(a.begin()+1, a.end());
        for (int i = 0; i < k-1; ++i)
            res += a[n-i-1];

        cout << res << endl;
    }
    return 0;
}