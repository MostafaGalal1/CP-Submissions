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
        ll a, b, c;
        cin >> a>> b >> c;

        if (a == b+c)
            cout << "YES";
        else if (b == a+c)
            cout << "YES";
        else if (c == b+a)
            cout << "YES";
        else
            cout <<"NO";
        cout << endl;
    }

    return 0;
}