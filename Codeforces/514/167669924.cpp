#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e4 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, ss;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (i == 0 && s[i] == '9')
            ss += s[i];
        else if (s[i] - '0' > 4)
            ss += 9 - (s[i] - '0') + '0';
        else
            ss += s[i];
    }

    cout << ss << endl;

    return 0;
}