#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        int n;
        cin >> n;

        string s = bitset<32>(n).to_string(), s1, s2;
        bool xo = true;

        for (int i = 31; i >= 0; --i) {
            if (s[i] - 48){
                if (xo) {
                    s1 = '1' + s1;
                    s2 = '0' + s2;
                } else {
                    s1 = '0' + s1;
                    s2 = '1' + s2;
                }
                xo ^= true;
            } else {
                if (i && s[i-1] - 48){
                    s1 = '1' + s1;
                    s2 = '1' + s2;
                } else {
                    s1 = '0' + s1;
                    s2 = '0' + s2;
                }
            }
        }

        ll n1 = stoll(s1, 0, 2), n2 = stoll(s2, 0, 2);
        if ((n1 + n2) / 2 == (n1 ^ n2))
            cout << n2 << ' ' << n1;
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}