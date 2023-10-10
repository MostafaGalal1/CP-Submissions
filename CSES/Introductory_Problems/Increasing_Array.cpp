#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

int main() {
    ll n, num, pre = 0, sum = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num <= pre) {
            sum += pre - num;
        } else {
            pre = num;
        }
    }

    cout << sum << endl;

    return 0;
}