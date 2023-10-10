#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    ll mx = 0, n1, n2;

    for (int i = 0; i < t; ++i) {
        cin >> n1 >> n2;
        mx = max(mx, (n1 + n2));
    }

    cout << mx << endl;

    return 0;
}