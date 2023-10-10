#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        ll n = (ll)s.length();

        ll st = n-1, en = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '1')
                s[i] = '0';
            else {
                st = i;
                break;
            }
        }

        for (int i = n-1; i >= 0; --i) {
            if (s[i] != '0')
                s[i] = '1';
            else {
                en = i;
                break;
            }
        }

        for (int i = st; i <= en; ++i) {
            if (s[i] == '?') {
                if (i < n - 1 && s[i+1] != '?')
                    s[i] = s[i+1];
                else if (i && s[i-1] != '?')
                    s[i] = s[i-1];
            }
        }

        cout << s << endl;
    }

    return 0;
}
