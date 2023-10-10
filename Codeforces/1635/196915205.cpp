#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mxx (LONG_LONG_MAX - (ll)(1e5 - 100))
#define mnn (LONG_LONG_MIN + (ll)(1e5 + 100))

int main()
{
    ll t, tt;
    cin >> t;
    tt = t;

    while (t --> 0) {
        ll n;
        cin >> n;
        ll xo = 0, nu;
        vector<ll>a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll ind, cnt = 0, res = 0;
        for (int i = 1; i < n-1; ++i) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) {
                if (cnt) {
                    res += cnt;
                    a[i-1] = max(a[i-2], a[i]);
                    cnt = -1;
                }
                ind = i;
                cnt++;
            }
            if(i == ind+2 && cnt) {
                a[ind] = max(a[ind-1], a[ind+1]);
                res += cnt;
                cnt = 0;
            }
        }

        if (cnt == 1) {
            res += cnt;
            a[n-1-1] = max(a[n-1-2], a[n-1]);
        }

        cout << res << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}