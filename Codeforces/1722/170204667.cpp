#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 4e5 + 10;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        map<string, bool> a, b, c;
        int n, as = 0, bs = 0, cs = 0;
        string s;
        cin >> n;
        set<string> se;

        for (int i = 0; i < n; i++) {
            cin >> s;
            a[s] = true;
            se.insert(s);
        }

        for (int i = 0; i < n; i++) {
            cin >> s;
            b[s] = true;
            se.insert(s);
        }

        for (int i = 0; i < n; i++) {
            cin >> s;
            c[s] = true;
            se.insert(s);
        }

        for (auto & i : se) {
            if (a[i] && b[i] && c[i]) {
                continue;
            } else if (a[i] && b[i]) {
                as++, bs++;
            } else if (a[i] && c[i]) {
                as++, cs++;
            } else if (c[i] && b[i]) {
                cs++, bs++;
            } else if (a[i]) {
                as += 3;
            } else if (c[i]) {
                cs += 3;
            } else if (b[i]) {
                bs += 3;
            }
        }

        cout << as << ' ' << bs << ' ' << cs << endl;
    }

    return 0;
}