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

        if (n%2){
            cout << "YES" << endl;
            ll f = 1, s = 2*n;
            ll i;
            for (i = 0; s - 2 * i > n; ++i) {
                cout << f + i << ' ' << s - 2 * i << endl;
            }
            for (ll j = i; s - 1 - 2 * (j - i) > n; ++j) {
                cout << f + j << ' ' << s - 1 - 2 * (j-i) << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}