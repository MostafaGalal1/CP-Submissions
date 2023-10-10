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
        ll n;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        if (n == 1){
            cout << 0 << endl;
        } else {
            int par, ind;
            vector<pair<ll, ll>> ve;

            if (arr[0]%2)
                par = 1;
            else
                par = 0;

            for (int i = n-1; i >= 0; --i) {
                if (arr[i]%2 == par) {
                    ind = i;
                    break;
                }
            }

            cout << n-1 << endl;
            for (int i = 0; i < n; ++i) {
                if (arr[i]%2 == par && i != ind)
                    cout << i+1 << ' ' << ind+1 << endl;
            }

            for (int i = 0; i < n; ++i) {
                if (arr[i]%2 != par)
                    cout << 1 << ' ' << i+1 << endl;
            }
        }
    }
}