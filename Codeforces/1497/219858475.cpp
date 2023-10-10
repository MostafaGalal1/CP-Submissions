#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, k;
        cin >> n >> k;

        if (n%2)
            cout << n/2 << ' ' << n/2 << ' ' << 1;
        else if (n%4 == 0)
            cout << n/2 << ' ' << n/4 << ' ' << n/4;
        else
            cout << n/2-1 << ' ' << n/2-1 << ' ' << 2;
        cout << endl;
    }
    return 0;
}