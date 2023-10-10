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

    while (t --> 0){
        int n;
        cin >> n;

        if (n == 1)
            cout << 2;
        else if (n == 2 || n == 3)
            cout << 1;
        else
            cout << (int)round((n+1)/3.0);
        cout << endl;
    }
    return 0;
}