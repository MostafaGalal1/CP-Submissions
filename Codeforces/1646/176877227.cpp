#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n, s;
        cin >> n >> s;

        ll res = s/(n * n);
        cout << res << endl;
    }
    return 0;
}