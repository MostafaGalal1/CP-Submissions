#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    cout << c * 2 + 2 * min(a,b) + min(1ll, abs(a - b)) << endl;
}