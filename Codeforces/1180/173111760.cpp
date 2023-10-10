#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

        ll n;
        cin >> n;

        cout << 3 + 4 * (n-1) * n - (n - 2) * (n - 1) - n * (n + 1) << endl;

    return 0;
}