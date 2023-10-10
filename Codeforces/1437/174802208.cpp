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
        ll n, mn1 = 0, mn2 = 0;
        string s, s1, s2;
        cin >> n >> s;

        for (int i = 0; i < n; ++i) {
            if (i%2) {
                if (s[i] == '1')
                    s1 += '0', s2 += '1';
                else
                    s1 += '1', s2 += '0';
            } else {
                if (s[i] == '1')
                    s1 += '1', s2 += '0';
                else
                    s1 += '0', s2 += '1';
            }
        }

        if (s1[n-1] == '1')
            s1 += '0';
        else
            s1 += '1';

        if (s2[n-1] == '1')
            s2 += '0';
        else
            s2 += '1';

        for (int i = 0; i < n; ++i) {
            if (s1[i] == '1' && s1[i] != s1[i+1])
                mn1++;
            if (s2[i] == '1' && s2[i] != s2[i+1])
                mn2++;
        }

        cout << min(mn1, mn2) << endl;
    }
}