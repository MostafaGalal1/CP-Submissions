#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t, res = 0;
    char ch;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cin >> ch;
        if (!((ch - '0')%2))
            res += i;
    }

    cout << res << endl;
    return 0;
}