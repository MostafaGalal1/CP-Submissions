#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0){
        ll n, num, odds = 0, evens = 0;
        cin >> n;

        for (int i = 0; i < 2 * n; ++i) {
            cin >> num;
            if (num%2)
                odds++;
            else
                evens++;
        }

        if (odds == evens)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}