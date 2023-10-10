#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int x, y, n;
        cin >> x >> y >> n;

        if (n - n % x + y <= n) {
            cout << n - n % x + y << endl;
        } else {
            cout << n - n % x - (x - y) << endl;
        }
        cout << endl;
    }
}