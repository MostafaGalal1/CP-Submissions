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
        vector<ll> a(n);

        ll mx = 0, mn = LONG_LONG_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > mx)
                mx = a[i];
            if (a[i] < mn)
                mn = a[i];
        }

        for (int i = 0; i < n; ++i) {
            mx |= a[i];
            mn &= a[i];
        }

        cout << mx - mn << endl;
    }
    return 0;
}