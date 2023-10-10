#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, sx, sy, x, y;
    cin >> n >> sx >> sy;
    ll xp = 0, yp = 0, xn = 0, yn = 0;
    ll first = 0, second = 0, third = 0, fourth = 0;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x == sx) {
            if (y > sy)
                yp++;
            else
                yn++;
        } else if (y == sy) {
            if (x > sx)
                xp++;
            else
                xn++;
        } else if (x > sx && y > sy)
            first++;
        else if (x < sx && y > sy)
            second++;
        else if (x < sx && y < sy)
            third++;
        else if (x > sx && y < sy)
            fourth++;
    }

    ll one, two, three, four;
    one = fourth + xp + first, two = first + yp + second, three = second + xn + third, four = third + yn + fourth;
    if (one >= two && one >= three && one >= four)
        cout << one << '\n' << sx + 1 << ' ' << sy << endl;
    else if (two >= one && two >= three && two >= four)
        cout << two << '\n' << sx << ' ' << sy + 1 << endl;
    else if (three >= one && three >= two && three >= four)
        cout << three << '\n' << sx - 1 << ' ' << sy << endl;
    else if (four >= one && four >= two && four >= three)
        cout << four << '\n' << sx << ' ' << sy - 1 << endl;

    return 0;
}