#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int query(int l, int r, int p[]) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n, s, sum = 0, mn = -1;
        cin >> n >> s;
        int arr[n], pre[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
            pre[i] = sum;
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; ++i) {
            int l = i, r = n - 1, pos = -1;
            while(l <= r) {
                int mid = l + r >> 1;
                if(query(i, mid, pre) <= s) {
                    pos = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            if(pos == -1 || query(i, pos, pre) != s) continue;
            ans = min(ans, n - (pos - i + 1));
        }

        cout << ((ans == INT_MAX)? -1:ans) << endl;
    }
    return 0;
}