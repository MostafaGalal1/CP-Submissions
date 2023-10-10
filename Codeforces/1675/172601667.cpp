#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        string s;
        cin >> s;
        ll one = 0, zero = (ll)s.length()-1;

        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '1')
                one = i;
            else if (s[i] == '0') {
                zero = i;
                break;
            }
        }

        cout << zero - one + 1 << endl;
    }

    return 0;
}