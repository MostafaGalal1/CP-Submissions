#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ll n, mn = -1, ind = 0;
    cin >> n;
    vector<ll> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] >= 0)
            arr[i] = -arr[i] - 1;

        if (mn > arr[i]) {
            mn = arr[i];
            ind = i;
        }
    }

    if (n%2)
        arr[ind] = -arr[ind] - 1;

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}