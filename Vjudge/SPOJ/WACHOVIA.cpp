#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
ll dp[55][1050];
ll w[55], v[55];

ll solve(ll ind, ll cur_w){
    if (ind == m)
        return 0;
    if (~dp[ind][cur_w])
        return dp[ind][cur_w];
    return dp[ind][cur_w] = max(solve(ind + 1, cur_w), cur_w >= w[ind]? solve(ind + 1, cur_w - w[ind]) + v[ind]:0ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t --> 0){
        cin >> n >>  m;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < m; ++i) {
            cin >> w[i] >> v[i];
        }

        cout << "Hey stupid robber, you can get " << solve(0, n) << "." << endl;
    }
}