#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll x = a * d, y = b * c;
        if (x == y)
            cout << 0;
        else if (y != 0 && x % y == 0 || x != 0 && y % x == 0)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }
    return  0;
}
