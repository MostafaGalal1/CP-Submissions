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
        bool done = false;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n-1; ++i) {
            if (arr[i] == arr[i+1]){
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";
        cout << endl;
    }

    return 0;
}