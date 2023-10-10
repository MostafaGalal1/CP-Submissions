#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ld n, a, o, num = 0;
    cin >> n >> a;

    o = 180 / n;
    vector<ld> angles;
    angles.push_back(-181);

    if (a > o * (n-2))
        num++;

    for (int i = 1; i < n-1; ++i)
        angles.push_back(o * i);

    auto it = lower_bound(angles.begin(), angles.end(), a);

    if (it - angles.begin() == n){
        cout << "1 2 3" << endl;
        return 0;
    }
    if (a - angles[it - angles.begin() - 1] <= angles[it - angles.begin()] - a)
        num += n + 2 - (it - angles.begin());
    else
        num += n + 1 - (it - angles.begin());
    cout << "1 2 " << num << endl;

    return 0;
}