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

    int t;
    cin >> t;

    while (t-->0) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;

        a = ((p%a == 0? p/a: p/a+1) * a)-p;
        b = ((p%b == 0? p/b: p/b+1) * b)-p;
        c = ((p%c == 0? p/c: p/c+1) * c)-p;

        cout << min(min(a, b), c) << endl;
    }
    return 0;
}