#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll cal[4], sum = 0;
    cin >> cal[0] >> cal[1] >> cal[2] >> cal[3];

    string s;
    cin >> s;

    for (char i : s) {
        sum += cal[i - '1'];
    }

    cout << sum << endl;

    return 0;
}