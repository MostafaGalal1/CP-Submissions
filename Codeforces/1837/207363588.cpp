#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, cnt = 1, res = 2;
        string s;
        cin >> n >> s;

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                cnt++;
                res = max(cnt+1, res);
            } else
                cnt = 1;
        }

        cout << res << endl;
    }

    return 0;
}
