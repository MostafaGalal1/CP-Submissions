#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, cnt = 0, sz;
        cin >> n;

        if (n <= 9){
            cout << n << endl;
        } else if (n <= 17){
            cout << (n-9) << 9 << endl;
        } else if (n <= 24){
            cout << (n-17) << 8 << 9 << endl;
        } else if (n <= 30){
            cout << (n-24) << 7 << 8 << 9 << endl;
        } else if (n <= 35){
            cout << (n-30) << 6 << 7 << 8 << 9 << endl;
        } else if (n <= 39){
            cout << (n-35) << 5 << 6 << 7 << 8 << 9 << endl;
        } else if (n <= 42){
            cout << (n-39) << 4 << 5 << 6 << 7 << 8 << 9 << endl;
        } else if (n <= 44){
            cout << (n-42) << 3 << 4 << 5 << 6 << 7 << 8 << 9 << endl;
        } else {
            cout << 123456789 << endl;
        }
    }

    return 0;
}