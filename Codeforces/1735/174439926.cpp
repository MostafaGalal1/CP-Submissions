#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        cout << (n- 3)/3 - 1 << endl;
    }

    return 0;
}