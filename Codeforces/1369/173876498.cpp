#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        if (!(n%4))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}