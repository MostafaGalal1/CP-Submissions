#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << a/(b*d) * c + a/d << endl;
    }
    return 0;
}