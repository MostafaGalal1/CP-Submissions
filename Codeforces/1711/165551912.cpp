#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    for (ll h = 1; h <= t; h++) {
        ll n;
        cin >> n;

        if (n == 1)
            cout << 1 << " ";
        else {
            if (n % 2 == 1){
                cout << n << " " << 1 << " ";
                for (ll i = 2; i < n - 1; i += 2)
                    cout << i << " " << i + 1 << " ";
                cout << n - 1;
            } else {
                for (ll i = 2; i <= n; i += 2)
                    cout << i << " " << i - 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}