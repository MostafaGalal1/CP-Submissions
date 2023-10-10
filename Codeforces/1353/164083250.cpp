#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        long long n, k;
        cin >> n >> k;

        if (n == 1)
            cout << 0;
        else if (n == 2)
            cout << k;
        else
            cout << k * 2;
        cout << endl;
    }

    return 0;
}