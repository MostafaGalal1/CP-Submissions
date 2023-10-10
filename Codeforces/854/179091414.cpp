#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, k;
    cin >> n >> k;

    if (k == 0 || k == n)
        cout << 0 << ' ';
    else
        cout << 1 << ' ';

    if (k <= n/3) {
        cout << k * 2;
    } else
        cout << n - k;

    cout << endl;
    return 0;
}
