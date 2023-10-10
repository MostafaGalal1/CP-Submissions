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
        int n, m, num, sum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            sum += num;
        }
        cout << (sum == m? "YES":"NO") << endl;
    }
    return 0;
}