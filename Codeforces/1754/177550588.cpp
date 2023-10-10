#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        for (int i = n/2; i > 0; --i) {
            cout << i << ' ' << i + n/2 << ' ';
        }

        if (n%2)
            cout << n << ' ';

        cout << endl;
    }
    return 0;
}