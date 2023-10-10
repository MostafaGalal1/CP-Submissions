#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n, q, qq, sum = 0;
        cin >> n >> q;
        vector<int> arr(n), pre(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.rbegin(), arr.rend());

        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            pre[i] = sum;
        }

        int res = 0;
        for (int i = 0; i < q; ++i) {
            cin >> qq;
            auto it = lower_bound(pre.begin(), pre.end(), qq);

            res = it - pre.begin() + 1;
            cout << (res > n? -1:res) << endl;
        }
    }
    return 0;
}