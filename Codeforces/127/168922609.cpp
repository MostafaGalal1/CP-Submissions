#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

        ll n, k, x, y, curx, cury;
        double sum = 0;
        cin >> n >> k;

        cin >> curx >> cury;
        for (int i = 0; i < n-1; ++i) {
            cin >> x >> y;
            sum += sqrt((x - curx) * (x - curx) + (y - cury) * (y - cury));
            curx = x, cury = y;
        }

        cout << fixed << setprecision(9) << sum / 50 * k << endl;

    return 0;
}