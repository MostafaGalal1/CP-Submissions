#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n, m, x, y, p = 0;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p += a[i];
    }

    sort(a.begin(), a.end());

    cin >> m;

    for (int i = 0; i < m; ++i) {
        ll res = 0;
        cin >> x >> y;

        auto it = lower_bound(a.begin(), a.end(), x);

        if (it == a.end() || (it != a.begin() && *it > x && (max(y - (p - *it), 0ll) > x - *prev(it) + max(y - (p - *prev(it)), 0ll)))) {
            it = prev(it);
            res += x - *it;
        }

        res += max(y - (p - *it), 0ll);
        cout << res << endl;
    }
    return 0;
}