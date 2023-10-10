#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i)
                a[i] += a[i-1];
        }

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(a.begin(), a.end(), (i>0?a[i-1]:0) + k);
            if (*it - i?a[i-1]:0 <= k)
                res = max(res, (ll)(it - a.begin()) - i);
            else
                res = max(res, (ll)(it - a.begin()) - i - 1);
        }

        cout << res << endl;

    return 0;
}