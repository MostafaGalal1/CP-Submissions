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

    while(t -- > 0) {

        ll n, m, mx = 0, ind, u, r;
        cin >> n >> m;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] > mx){
                mx = arr[i];
                ind = i;
            }
        }

        vector<ll> dp(ind, 0ll);
        for (ll i = ind - 1; i > 0; --i) {
            if (arr[i] > arr[i-1])
                dp[i] += 1;
            else {
                for (ll j = i; j < ind; ++j) {
                    if (arr[j] < arr[i-1])
                        dp[i - 1] += 1, dp[j] = 0;
                    else
                        break;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> r;
            u--;
            if (u > ind)
                cout << 0;
            else if (u == ind)
                cout << (ind == 0? r : max(r - ind + 1, 0ll));
            else
                cout << (r < u? 0 : min((u == 0? r - u : r - u + 1), dp[u]));
            cout << endl;
        }
    }
    return 0;
}