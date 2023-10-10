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
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll last = 0;
        cout << last << ' ';
        for (int i = 1; i < n; ++i) {
            last = (last ^ a[i-1]) & ~a[i];
            cout << last << ' ';
        }
        cout << endl;
    }
    return 0;
}