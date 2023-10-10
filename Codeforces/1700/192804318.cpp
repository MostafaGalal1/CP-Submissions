#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        string s, r, k(n, '1');
        cin >> s;

        ll cnt = 0;

        for (int i = n-1; i >= 0; --i) {
            char ch = 57 - s[i] + cnt + 48;
            if (ch < 58) {
                r = ch + r;
                cnt = 0;
            } else {
                r = '0' + r;
                cnt++;
            }
        }

        cnt = 0;
        if (s[0] == '9'){
            for (int i = n-1; i >= 0; --i) {
                r[i] += 1 + !(n-1-i) + cnt;
                if (r[i] < 58) {
                    cnt = 0;
                } else {
                    r[i] = (r[i] - 48)%10 + 48;
                    cnt = 1;
                }
            }
        }

        cout << r << endl;
    }

    return 0;
}