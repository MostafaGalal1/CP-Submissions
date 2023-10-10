#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 3010;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;
    string s, ss;
    cin >> s;

    for (int i = 0; i < n; i += 2) {
        int ch1 = s[i] - 'a', ch2 = s[i + 1] - 'a';
        if (ch1 ^ ch2) {
            ss += s[i];
            ss += s[i + 1];
        } else {
            cnt++;
            ss += "ab";
        }
    }

    cout << cnt << endl << ss << endl;

    return 0;
}