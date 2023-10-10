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

    while (t --> 0) {
        ll n;
        string s;
        bool done = false;
        cin >> n >> s;

        ll u = 0;
        ll r = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U')
                u++;
            else if (s[i] == 'D')
                u--;
            else if (s[i] == 'R')
                r++;
            else
                r--;

            if (r == 1 && u == 1){
                cout << "YES";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "NO";
        cout << endl;
    }
    return 0;
}