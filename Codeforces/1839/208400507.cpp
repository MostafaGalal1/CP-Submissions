#include<bits/stdc++.h>

using namespace std;
#define int long long


void solve(int kkkk, int tttt)
{
    int n; cin >> n;
    vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
    int inf = 1e9;
//    vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(2, inf))));
    int dp[2][n+1][n+1][2];

    for (int k = 0; k <= n; k++)
        for (int m = 0; m <= n; m++)
            for (int taken = 0; taken < 2; taken++)
                dp[0][k][m][taken] = inf;

    dp[0][0][0][0] = 0;
    for (int index = 1; index <= n; index++)
    {
        int a = index % 2, b = 1-a;
        for (int k = 0; k <= n; k++)
            for (int m = 0; m <= n; m++)
                for (int taken = 0; taken < 2; taken++)
                    dp[a][k][m][taken] = inf;
        for (int k = 0; k <= n; k++)
        {
            for (int m = 0; m <= n; m++)
            {
                for (int taken = 0; taken < 2; taken++)
                {
                    // take it
                    if (taken)
                        dp[a][k][m][1] = min(dp[a][k][m][1], dp[b][k][m][taken]+1);
                    else
                        dp[a][min(k+1, n)][m][1] = min(dp[a][min(k+1, n)][m][1], dp[b][k][m][taken]+1);
                    // don't take it
                    if (arr[index-1] >= m)
                        dp[a][k][arr[index-1]][0] = min(dp[a][k][arr[index-1]][0], dp[b][k][m][taken]);
                }
            }
        }
    }
    vector<int> answers(n+1, inf);

    for (int k = 0; k <= n; k++)
        for (int m = 0; m <= n; m++)
            for (int taken = 0; taken < 2; taken++)
                answers[k] = min(answers[k], dp[n%2][k][m][taken]);
    for (int i = 1; i <= n; i++)
        answers[i] = min(answers[i], answers[i-1]);
    for (int i = 1; i <= n; i++) cout << answers[i] << " ";
    cout << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

signed main()
{
    //freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    fast();

//    int t = 0, i = 0;
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
    solve(t, i);
    return 0;
}