#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double s = a/b, z = c/d;

    double res = s, num = s;
    for (int i = 0; i < 2e5; ++i) {
        num *= (1-s)*(1-z);
        res += num;
    }

    cout << fixed << setprecision(12) << res << endl;

    return 0;
}