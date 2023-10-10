#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, x, y;
    cin >> n >> x >> y;
    n /= 2;

    if ((x == n || x == n+1) && (y == n || y == n+1))
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
