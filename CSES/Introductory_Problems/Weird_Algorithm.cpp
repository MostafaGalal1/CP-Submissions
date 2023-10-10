#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    while (n != 1){
        cout << n << ' ';
        if (n%2 == 0)
            n/=2;
        else {
            n *= 3;
            n++;
        }
    }

    cout << 1;

    return 0;
}