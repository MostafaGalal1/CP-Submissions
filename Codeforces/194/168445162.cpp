#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, num;
    cin >> n;

    while (n --> 0) {
        cin >> num;
        if (num%2 == 0)
            cout << num * 4 + 1;
        else if (num%4 == 1)
            cout << num * 2 + 1;
        else
            cout << num + 1;
        cout << endl;
    }

    return 0;
}