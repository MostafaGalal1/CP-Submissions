#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        bool done = false;
        ll n, num, sum = 0;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            sum += num;
            if (sum < i * (i+1) / 2) {
                done = true;
            }
        }

        if (!done){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}