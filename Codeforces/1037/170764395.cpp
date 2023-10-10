#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, q, cnt = 0;
    cin >> n >> q;
    vector<ll> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (arr[n/2] == q)
        cout << 0;
    else if (arr[n/2] > q) {
        for (ll i = n/2; i >= 0; --i) {
            if (arr[i] <= q)
                break;
            cnt += arr[i] - q;
        }
        cout << cnt;
    } else {
        for (ll i = n/2; i < n; ++i) {
            if (q <= arr[i])
                break;
            cnt += q - arr[i];
        }
        cout << cnt;
    }
    cout << endl;

    return 0;
}