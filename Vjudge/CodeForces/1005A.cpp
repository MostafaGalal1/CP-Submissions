#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pre, num, cnt = 0;
    cin >> n;
    int res[n];

    cin >> pre;
    for (int i = 0; i < n-1; ++i) {
        cin >> num;
        if (num == 1) {
            res[cnt] = pre;
            cnt++;
        }
        pre = num;
    }

    res[cnt] = pre;
    cnt++;

    cout << cnt << "\n";

    for (int i = 0; i < cnt; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}