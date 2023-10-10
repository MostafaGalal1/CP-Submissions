#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 998244353;

vector<vector<ll>> mem(65, vector<ll>(65, 0));

void build()
{
    mem[0][0] = 1;
    for (int i = 1; i < 65; i++)
    {
        mem[i][0] = 1;
        for (int j = 1; j < 65; j++)
        {
            mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 1];
            mem[i][j] %= MOD;
        }
    }
}

int main() {
    ll t;
    cin >> t;

    build();

    while (t --> 0){
        int n, m;
        ll res = 0;
        cin >> n;

        m = n;

        while (n > 2) {
            res += mem[n - 1][n/2 - 1];
            res %= MOD;
            res += mem[n - 4][n/2 - 1];
            res %= MOD;
            n -= 4;
        }

        res += (n%4? 1:0);
        cout << res << ' ' << ((mem[m][m/2] - 1 - res)%MOD + MOD)%MOD << ' ' << 1 << endl;
    }
    return 0;
}