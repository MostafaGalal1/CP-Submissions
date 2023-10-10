#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll mx = 0;
        string s;
        cin >> s;
        s = 'R' + s + 'R';

        ll next, pre = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'R') {
                next = i, mx = max(mx, next - pre);
                pre = next;
            }
        }

        cout << mx << endl;

    }

    return 0;
}
