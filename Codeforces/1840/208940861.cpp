#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        string s, r;
        cin >> n >> s;
        char cur = '+';

        for (int i = 0; i < n; ++i) {
            if (cur == '+'){
                cur = s[i];
            } else if (cur == s[i])
                r += s[i], cur = '+';
        }
        cout << r << endl;
    }

    return 0;
}
