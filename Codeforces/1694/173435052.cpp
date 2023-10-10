#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll a, b, xorr;
        cin >> a >> b;

        if (a <= b) {
            xorr = 1;
        } else {
            xorr = 0;
        }

        ll sz= a+b;
        for (int i = 0; i < sz; ++i) {
            if (!xorr)
                cout << '0', a--;
            else
                cout << '1', b--;
            if ((!xorr && b > 0) || (xorr && a > 0))
                xorr ^= 1;
        }

        cout << endl;
    }

    return 0;
}