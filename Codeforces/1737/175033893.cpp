#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll l, r;
        cin >> l >> r;

        ll sl = (ll)(sqrtl(l)), sr = (ll)(sqrtl(r));
        ll res = (sr - sl) * 3;

        for (int i = 0; i < 3; ++i) {
            if (sl * (sl + i) < l)
                res--;
            if (sr * (sr + i) <= r)
                res++;
        }

        cout << res << endl;
    }
}