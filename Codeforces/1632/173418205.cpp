#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        bool done = false;
        cin >> n;
        string s;
        cin >> s;

        if ((ll)s.length() > 2 || s == "11" || s == "00") {
            cout << "NO";
            done = true;
        }

        if (!done) {
            cout << "YES";
        }
        cout << endl;
    }

    return 0;
}