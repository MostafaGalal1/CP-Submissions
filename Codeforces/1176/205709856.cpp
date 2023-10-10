#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    m[4] = 0, m[8] = 1, m[15] = 2, m[16] = 3, m[23] = 4, m[42] = 5;
    vector<ll> a(n);
    vector<vector<ll>> dp(n, vector<ll>(6, 0));

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (!m[a[0]])
        dp[0][0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 6; ++j)
            dp[i][j] += dp[i - 1][j];
        if (!m[a[i]] || dp[i-1][m[a[i]]-1] > dp[i][m[a[i]]])
            dp[i][m[a[i]]]++;
    }

    cout << n - dp[n-1][5] * 6 << endl;
    return 0;
}