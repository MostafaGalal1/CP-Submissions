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

    while (t-->0) {
        ll n;
        cin >> n;

        bool xo = true;
        string s = to_string(n), s1, s2;
        for (int i = 0; i < s.length(); ++i) {
            char ch;
            if (xo){
                ch = (int)floor((s[i] - 48)/2.0) + 48;
                s1 += ch;
                ch = (int)ceil((s[i] - 48)/2.0) + 48;
                s2 += ch;
            } else {
                ch = (int)floor((s[i] - 48)/2.0) + 48;
                s2 += ch;
                ch = (int)ceil((s[i] - 48)/2.0) + 48;
                s1 += ch;
            }
            if (s[i]%2)
                xo ^= true;
        }
        cout << stoll(s1) << ' ' << stoll(s2) << endl;
    }

    return 0;
}