#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    cout << (3*n - k > 0? 3*n-k:0);
    cout << endl;

    return 0;
}