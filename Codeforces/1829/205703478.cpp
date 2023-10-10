#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ll t;
    cin >> t;
    
    while (t --> 0){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n+1);
        vector<vector<ll>> dp(n+1, vector<ll>(64, 0));
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 64; ++j) {
                dp[i][j] += dp[i][j] + dp[i-1][j];
                dp[i][j] = dp[i][j] % (ll)(1e9 + 7);
                dp[i][j&a[i]] += dp[i-1][j];
                dp[i][j&a[i]] = dp[i][j&a[i]] % (ll)(1e9 + 7);
            }
            dp[i][a[i]] += 1;
            dp[i][a[i]] = dp[i][a[i]] % (ll)(1e9 + 7);
        }

        ll res = 0;
        for (int i = 0; i < 64; ++i) {
            if (__builtin_popcount(i) == k) {
                res += dp[n][i];
                res = res % (ll)(1e9 + 7);
            }
        }
        
        cout << res << endl;
    }
    return 0;
}