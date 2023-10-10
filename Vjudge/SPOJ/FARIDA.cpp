#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t, tt;
    cin >> t;
    tt = t;
//    t = 1;

    while(t --> 0) {
        ll n;
        cin >> n;

        if (!n){
            cout << "Case " + to_string(tt-t) + ": " + to_string(0) << endl;
            continue;
        }

        vector<ll> a(n), dp(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        dp[0] = a[0], dp[1] = max(a[0], a[1]);
        for (int i = 2; i < n; ++i)
            dp[i] = max(a[i] + dp[i-2], dp[i-1]);

        cout << "Case " + to_string(tt-t) + ": " + to_string(dp[n-1]) << endl;
    }
    return 0;
}