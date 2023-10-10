#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n, num;
        string s, ans;
        char ss;
        cin >> n >> s;

        for (int i = 0; i < n; ++i) {
            if (i < n-2 && s[i+2] == '0' && s[i+3] != '0') {
                num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                ss = num - 1 + 'a', i += 2;
            } else
                ss = s[i] - '0' - 1 + 'a';
            ans += ss;
        }
        
        cout << ans << endl;
    }

    return 0;
}
