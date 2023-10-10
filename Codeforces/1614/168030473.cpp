#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 3010;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0){
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        auto it = lower_bound(arr.begin(), arr.end(), l);

        auto i = it;
        while (arr[i-arr.begin()] <= r && arr[i-arr.begin()] <= k && i-arr.begin() < n){
            k -= arr[i-arr.begin()];
            i++;
        }

        cout << i - it << endl;
    }
    return 0;
}