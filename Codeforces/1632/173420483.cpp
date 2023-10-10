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
        ll n;
        cin >> n;
        n--;

        ll lim = (ll)pow(2, floor(log2(n)));
        for (ll i = 1; i < lim; ++i) {
            cout << i << ' ';
        }
        cout << 0 << ' ';
        for (ll i = lim; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}