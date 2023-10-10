#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = INT_MAX;
const ll N = 1e5 + 10;

int main() {
    ll cnt = 1, mx = 1;
    string s;
    cin >> s;

    char pre = 'l';
    for (char i : s) {
        if (i != pre){
            cnt = 1;
        } else {
            mx = max(++cnt, mx);
        }
        pre = i;
    }

    cout << mx << endl;

    return 0;
}