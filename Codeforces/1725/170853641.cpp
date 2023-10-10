#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main() {
    fast();

    ll a, b;
    cin >> a >> b;

    if (b == 1)
        cout << a-1;
    else
        cout << a * (b-1);
    cout << endl;

    return 0;
}