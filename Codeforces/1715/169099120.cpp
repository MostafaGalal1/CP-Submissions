#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m;

        cin >> n >>m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else
            cout << (min(n, m) - 1) * 2 +max(n ,m) << endl;
    }
    return  0;
}
