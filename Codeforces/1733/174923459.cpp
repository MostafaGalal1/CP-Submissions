#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 100;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, m, sum = 0;
        cin >> n >> m;
        vector<ll> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < m; ++i) {
            ll mx = 0;
            for (int j = i; j < n; j += m) {
                mx = max(mx, arr[j]);
            }
            sum += mx;
        }

        cout << sum << endl;
    }

    return 0;
}