#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

int main() {
    ll n, num, sum = 0;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> num;
        sum += num;
    }

    cout << n*(n+1)/2 - sum;

    return 0;
}