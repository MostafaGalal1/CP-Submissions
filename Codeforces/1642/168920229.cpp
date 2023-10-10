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

    ll t;
    cin >> t;

    while (t --> 0){
        pair<ll, ll> a, b, c;
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;

        double s1, s2, s3, d1, d2, d3, sum = 0;

        d1 = sqrt((b.second - a.second) * (b.second - a.second) + (b.first - a.first) * (b.first - a.first));
        d2 = sqrt((c.second - a.second) * (c.second - a.second) + (c.first - a.first) * (c.first - a.first));
        d3 = sqrt((b.second - c.second) * (b.second - c.second) + (b.first - c.first) * (b.first - c.first));
        s1 = (b.second - a.second) / max((double)(b.first - a.first), 0.000001);
        s2 = (c.second - a.second) / max((double)(c.first - a.first), 0.000001);
        s3 = (b.second - c.second) / max((double)(b.first - c.first), 0.000001);

        if (s1 == 0 && c.second < a.second){
            sum = d1;
        } else if (s2 == 0 && b.second < a.second){
            sum = d2;
        } else if (s3 == 0 && a.second < c.second){
            sum = d3;
        }

        cout << fixed << setprecision(17) << sum << endl;
    }

    return 0;
}