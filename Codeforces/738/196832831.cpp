#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    bool done = false;
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    ll res = 0, cnt = 0;
    bool f = false;

    for (int i = 0; i < n; ++i) {
        cnt = 0;
        f = false;
        for (int j = 0; j < m; ++j) {
            if (a[i][j]) {
                res += cnt + (f?cnt:0);
                f = true;
                cnt = 0;
            } else
                cnt++;
        }
        if (f)
            res += cnt;
    }

    for (int i = 0; i < m; ++i) {
        cnt = 0;
        f = false;
        for (int j = 0; j < n; ++j) {
            if (a[j][i]) {
                res += cnt + (f?cnt:0);
                f = true;
                cnt = 0;
            } else
                cnt++;
        }
        if (f)
            res += cnt;
    }

    cout << res << endl;
}