#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        long long n = 0, k = 0, sum = 0;
        cin >> n >> k;
        long long a[n], b[n];

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a, a + n);
        sort (b, b + n);

        for (int i = 0; i < n; ++i) {
            if (i < k && a[i] < b[n-1-i])
                sum += b[n-1-i];
            else
                sum += a[i];
        }

        cout << sum << endl;
    }

    return 0;
}