#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> a(n), b(n);
        vector<ll> p(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        p[0] = a[0].second;
        ll res = b[0].second + p[0];
        for (int i = 1; i < n; ++i) {
            if (p[i-1] > a[i].second)
                p[i] = a[i].second;
            else
                p[i] = p[i-1];
            res = min(res, b[i].second + p[i]);
        }

        cout << res << endl;
    }
    return 0;
}