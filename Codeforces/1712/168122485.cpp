#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e6 + 7;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n;
        cin >> n;

        if (n%2){
            cout << 1 << ' ';
            for (int i = 2; i <= n; i += 2) {
                cout << i + 1 << ' ' << i << ' ';
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n; i += 2) {
                cout << i + 1 << ' ' << i << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}