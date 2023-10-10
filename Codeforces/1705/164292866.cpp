#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
   long long t;
   cin >> t;

    while (t --> 0) {
        long long n, sum = 0, zeros = 0;
        cin >> n;
        vector<long long> a(n);

        for (long long i = 0; i < n-1; i++) {
            cin >> a[i];
            sum += a[i];
            if (sum > 0 && a[i] == 0)
                zeros++;
        }
        cin >> a[n-1];

        cout << (sum + zeros) << endl;
    }
    return 0;
}