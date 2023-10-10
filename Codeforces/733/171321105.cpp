#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = 1e8;
const ll N = 2e6 + 7;

int main() {
    ll mx = 0;
    string s;
    cin >> s;
    s += 'A';

    ll prev = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A' || s[i] == 'Y' || s[i] == 'O' || s[i] == 'E' || s[i] == 'U' || s[i] == 'I')
            mx = max(mx, i - prev), prev = i;
    }

    cout << mx << endl;

    return 0;
}