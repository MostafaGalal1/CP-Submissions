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
        ll a, b, c;
        cin >> a >> b >> c;

        ll diff = abs(2*b - a - c);
        cout << (diff%3? 1:0) << endl;
    }
}