#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t --> 0){
        ll n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0;
        else if ((n == 1 && m > 2) || (m == 1 && n > 2))
            cout << -1;
        else {
            if (n%2 == m%2)
                cout << n + m - 2 + abs(n - m);
            else
                cout << n + m - 2 + abs(n - m) - 1;
        }
        cout << endl;
    }
    return 0;
}