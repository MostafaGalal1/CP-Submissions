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
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll cnt = 0;
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == '0' && s[i+1] == '0'){
                cnt+=2;
            } else if (i && s[i] == '1' && s[i+1] == '0') {
                if (s[i - 1] == '0') {
                    cnt++;
                    i++;
                }
            } else if (i < n-2 && s[i] == '0' && s[i+1] == '1') {
                if (s[i+2] == '0') {
                    cnt++;
                    i++;
                }
            } else if (s[i] == '1' && s[i+1] == '1') {
                i++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}