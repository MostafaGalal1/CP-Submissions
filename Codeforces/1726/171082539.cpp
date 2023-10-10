#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void fast() { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
}

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, mnn = LONG_MAX, mxx = 0, d = 0;
        cin >> n;
        ll arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            mxx = max(mxx, arr[i]);
            mnn = min(mnn, arr[i]);
            if (i > 0) {
                d = max(d, arr[i - 1] - arr[i]);
            }
        }

        cout << max(max(mxx - arr[0], arr[n-1] - mnn), d) << endl;
    }

    return 0;
}