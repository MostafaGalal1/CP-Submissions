#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, x, y;
        bool xb, yb;
        cin >> n >> x >> y;
        xb = x != 0, yb = y != 0;

        if (xb ^ yb) {
            n--;
            ll inc = max(x, y);
            if (n%inc && inc != 1)
                cout << -1;
            else{
                if (inc == 1)
                    n++;
                for (int i = 2; i <= n; i += inc) {
                    for (int j = 0; j < inc; ++j) {
                        cout << i << ' ';
                    }
                }
            }
        } else 
            cout << "-1";

        cout << endl;
    }
}