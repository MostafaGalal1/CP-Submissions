#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n;;
        cin >> n;

        ll sum = 0;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        ll res = sum;
        for (int i = 0; i < n-1; ++i) {
            res += b[i];
        }

        cout << res << endl;
    }
    return 0;
}