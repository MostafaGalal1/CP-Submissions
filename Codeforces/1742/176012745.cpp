#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ll t;
    cin >> t;

    while (t --> 0)
    {
        ll n, q, k;
        cin >> n >> q;
        vector<ll> pre(n);
        vector<ll> arr(n);

        cin >> arr[0];
        pre[0] = arr[0];
        for (int i = 1; i < n; ++i)
        {
            cin >> arr[i];
            pre[i] = arr[i] + pre[i-1];
            arr[i] = max(arr[i], arr[i - 1]);
        }

        for (int i = 0; i < q; ++i)
        {
            cin >> k;
            auto it = upper_bound(arr.begin(), arr.end(), k);
            if (it - arr.begin() == 0)
            {
                cout << 0 << ' ';
                continue;
            }
            it--;
            int index = it - arr.begin();
            cout << pre[index] << " ";
        }
        cout << endl;
    }

    return 0;
}