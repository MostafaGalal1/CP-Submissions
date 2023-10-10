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
        ll n;
        cin >> n;

        if (n%2) {
            cout << n-3 << ' ' << n-2 << ' ';
        } else {
            cout << n-2 << ' ' << n-3 << ' ';
        }
        for (ll i = n - 4; i > 0; --i) {
            cout << i << ' ';
        }
        cout << n-1 << ' ' << n;

        cout << endl;
    }


    return 0;
}