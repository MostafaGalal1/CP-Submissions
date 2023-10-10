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
        bool done = false;
        ll cnt = 0;
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll zcnt = 0;
        ll pcnt = 0;
        ll mxn = LONG_LONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= 0) {
                cnt++;
                if (!a[i])
                    zcnt++;
                if (i>0)
                    mxn = min(a[i] - a[i-1], mxn);
            } else {
                if (a[i] <= abs(mxn)) {
                    pcnt++;
                }
                break;
            }
        }

        if (zcnt <= 1)
            cnt += pcnt;

        cout << max(cnt,1ll) << endl;
    }
    return 0;
}