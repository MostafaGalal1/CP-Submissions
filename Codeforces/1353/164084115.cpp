#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        long long n = 0, sum = 0;
        cin >> n;

        for (int i = 0; i < n/2; ++i) {
            sum += ((n - 2*i) * 4 - 4) * (n / 2 - i);
        }

        cout << sum << endl;
    }

    return 0;
}