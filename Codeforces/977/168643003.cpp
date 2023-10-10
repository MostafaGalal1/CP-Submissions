#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);

    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (k == 0){
        if (arr[0] == 1)
            cout << -1;
        else
            cout << 1;
    } else if (arr[k] > arr[k-1] || n == k)
        cout << arr[k-1];
    else
        cout << -1;

    cout << endl;
    return 0;
}