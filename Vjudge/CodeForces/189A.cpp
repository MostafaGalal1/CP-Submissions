#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
//    cin >> t;
    t = 1;

    while(t --> 0) {
        ll n, nu;
        cin >> n;
        set<ll> s;
        vector<ll> dp(4001, 0);

        for (int i = 0; i < 3; ++i) {
            cin >> nu;
            s.insert(nu);
            if (!dp[nu])
                dp[nu]++;
        }

        vector<ll> a(s.begin(), s.end());
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < (ll)a.size(); ++j) {
                if (i-a[j] >= 0 && dp[i-a[j]])
                    dp[i] = max(dp[i-a[j]] + 1, dp[i]);
            }
        }

        cout << dp[n] << endl;
    }
    return 0;
}