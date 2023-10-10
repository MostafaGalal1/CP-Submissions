#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        cin >> n;

        if (n*(n+1)%4)
            cout << "NO";
        else {
            cout << "YES" << endl;
            bool xo = false;
            cout << n/2 << endl;
            for (int i = n; i >= 1; i-=(xo?3:1)) {
                cout << i << ' ';
                xo ^= true;
            }
            cout << endl;
            xo = true;
            cout << (n+1)/2 << endl;
            for (int i = n-1; i >= 1; i-=(xo?3:1)) {
                cout << i << ' ';
                xo ^= true;
            }
            cout << endl;
        }
    }

    return 0;
}