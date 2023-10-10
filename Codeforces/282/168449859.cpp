#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool ap = false, bp = false;
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length())
        cout << "NO";
    else {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == '1')
                ap = true;

            if (b[i] == '1')
                bp = true;
        }
        if (ap && bp || a == b)
            cout << "YES";
        else
            cout << "NO";
    }
    cout << endl;
}