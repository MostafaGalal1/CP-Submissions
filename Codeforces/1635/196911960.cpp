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

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            xo |= nu;
        }

        cout << xo << endl;
    }
}