#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main() {

    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m, d, sx, sy;

        cin >> n >> m >> sx >> sy >> d;
        sx-=1, sy-=1;

        bool hh1 = true, hh2 = true, vv1 = true, vv2 = true;

        int nr1 = 0, nr2 = n-1, nc1 = 0, nc2 = m-1;
        int x = 0, y = 0;

        for (int i = 0; i < n; ++i) {
            if (abs(sy - nc1) + abs(sx - x) <= d)
                vv1 = false;
            if (abs(sy - nc2) + abs(sx - x) <= d)
                vv2 = false;
            x++;
        }

        for (int i = 0; i < m; ++i) {
            if (abs(sy - y) + abs(sx - nr1) <= d)
                hh1 = false;
            if (abs(sy - y) + abs(sx - nr2) <= d)
                hh2 = false;
            y++;
        }

        if ((hh1 && vv2) || (hh2 && vv1))
            cout << n + m - 2 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
