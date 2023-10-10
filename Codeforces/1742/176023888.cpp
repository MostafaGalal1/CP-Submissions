#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    int n; cin >> n;
    vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> match;
    unordered_map<int, int> mapp;
    for (int i = 0; i < n; i++)
    {
        mapp[arr[i]]++;
        match[arr[i]] = i + 1;
    }
    int ans = -1;
    for (int i = 1; i <= 1005; i++)
    {
        for (int j = i; j <= 1005; j++)
        {
            if (__gcd(i, j) == 1 && mapp.count(i) && mapp.count(j))
                ans = max(ans, match[i] + match[j]);
        }
    }
    cout << ans << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();


//    int t = 0, i = 0;

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(t, i);
    return 0;
}