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
        ll n, su = 0;
        cin >> n;
        vector <ll> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            su += arr[i];
        }

        ll sm1 = 0, maxi = 0;
        for (int i = 1; i < n; i++)
        {
            sm1 += arr[i];
            if (sm1 < 0) sm1 = 0;
            maxi = max(maxi, sm1);
        }

        ll sm2 = 0;
        for (int i = 0; i < n-1; i++)
        {
            sm2 += arr[i];
            if (sm2 < 0) sm2 = 0;
            maxi = max(maxi, sm2);
        }

        if (su > maxi) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}