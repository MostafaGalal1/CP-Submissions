#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x = 0;
    string s;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[1] == '+')
            x++;
        else
            x--;
    }

    cout << x << endl;
}