#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 510;

int main() {

    ll n;
    cin >> n;
    ll l[n], r[n];
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (r[i] - l[i] < ans || n-i < ans+1)
                break;
            ll a = i + ans;
            ll b = max(l[i], l[a]);
            if (b + ans - 1 < r[i] && b + ans -1 < r[a])
                ans++;
        }
    }
    cout << ans;
    return 0;;
}