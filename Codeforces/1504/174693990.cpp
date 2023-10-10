#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        string s;
        cin >> s;

        string a(s.length(), 'a');
        if (s == a)
            cout << "NO";
        else {
            cout << "YES" << endl;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != 'a') {
                    cout << s.substr(0, s.length() - i) + "a" + s.substr(s.length() - i, i);
                    break;
                }
            }
        }
        cout << endl;
    }
}