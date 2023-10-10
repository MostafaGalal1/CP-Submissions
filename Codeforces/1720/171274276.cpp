#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t --> 0) {
        int n, mx1 = 0, mn1 = INT_MAX, ix1, in1, mx2 = 0, mn2 = INT_MAX;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx1 = max(mx1, a[i]);
            mn1 = min(mn1, a[i]);
            if (a[i] == mx1)
                ix1 = i;
            if (a[i] == mn1)
                in1 = i;
        }

        for (int i = 0; i < n; ++i) {
            if (mx2 < a[i] && i != ix1)
                mx2 = a[i];
            if (mn2 > a[i] && i != in1)
                mn2 = a[i];
        }

        cout << mx1 - mn1 + mx2 - mn2 << endl;
    }
    return 0;
}