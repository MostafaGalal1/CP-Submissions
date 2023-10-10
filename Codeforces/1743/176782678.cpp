#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 0;
        ll mx = 0, mn = LONG_LONG_MAX;

        bool z = false, o = false;
        for (ll i = 0; i < n; ++i) {
            if (s[i] == '0' && z && o){
                if (mn <= mx){
                    res += mx;
                    res -= mn;
                }
                mx  = 0;
                mn = LONG_LONG_MAX;
                o = z = false;
            }
            if (s[i] == '0' && s[i+1] == '1'){
                mx = a[i];
                z = true;
                o = false;
            }
            if (s[i] == '1'){
                if (z)
                    mn = min(mn, a[i]);
                res += a[i];
                o = true;
            }
        }

        if (z && o){
            if (mn <= mx){
                res += mx;
                res -= mn;
            }
            mx  = 0;
            mn = LONG_LONG_MAX;
            z = o = false;
        }

        cout << res << endl;
    }
    return 0;
}