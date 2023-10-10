#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {

        ll n, q, cnt = 0;
        cin >> n >> q;
        vector<ll> arr(n + 1);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        arr[n] = 0;

        sort(arr.begin(), arr.end());

        auto it = lower_bound(arr.begin(), arr.end(), 0);

        ll loc = it - arr.begin();
        ll pos = n - loc, neg = loc;
        ll l = loc - neg % q, r = loc + pos % q;

        ll sz = max(neg, pos) / q;
        for (ll i = 0; i <= sz; i++) {
            cnt += (l >= 0? abs(arr[l]) * 2:0) + (r <= n? abs(arr[r]) * 2:0);
            l -= q, r += q;
        }

        cnt -= max(abs(arr[0]), abs(arr[n]));

        cout << cnt << endl;
    }
    return 0;
}