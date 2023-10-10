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
        ll n, m;
        cin >> n >> m;

        if (min(n, m) > 0.5 * max(n, m))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}