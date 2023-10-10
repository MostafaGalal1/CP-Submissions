#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e6 + 7;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, k, count = 0;
        cin >> n >> k;
        vector<pair<ll, ll>> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i].first;
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < k; ++i) {
            if (arr[i].second >= k)
                count++;
        }

        cout << count << endl;
    }

    return 0;
}