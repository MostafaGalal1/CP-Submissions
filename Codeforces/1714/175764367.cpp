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
        ll n, h, m, H, M;
        cin >> n >> H >> M;

        vector<ll> ve;
        ve.push_back(H * 60 + M);
        for (int i = 0; i < n; ++i) {
            cin >> h >> m;
            ve.push_back(h * 60 + m);
        }

        std::sort(ve.begin(), ve.end());

        auto it = lower_bound(ve.begin(), ve.end(), H * 60 + M);

        if (it - ve.begin() == n){
            h = 24 * 60 - ve[n] + ve[0];
            cout << h/60 << ' ' << h%60 << endl;
        } else {
            h = abs(ve[it - ve.begin()+1] - ve[it-ve.begin()]);
            cout << h/60 << ' ' << h%60 << endl;
        }
    }

    return 0;
}