#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    ll t;

    cin >> t;

    while (t --> 0) {
        ll n, pos = 0, mmx = 0;
        cin >> n;
        ll a[n];

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (mmx < a[i]) {
                mmx = a[i];
                pos = i + 1;
            }
        }

        cout << pos << endl;
    }


    return 0;
}