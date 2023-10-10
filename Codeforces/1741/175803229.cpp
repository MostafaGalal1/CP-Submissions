#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        string a, b;

        cin >> a >> b;
        ll al = a.length()-1, bl = b.length()-1;
        if (a[al] == 'S' && b[bl] == 'M'){
            cout << '<';
        } else if (a[al] == 'L' && b[bl] == 'M'){
            cout << '>';
        } else if (a[al] == 'M' && b[bl] == 'S') {
            cout << '>';
        } else if (a[al] == 'M' && b[bl] == 'L') {
            cout << '<';
        } else if (a[al] == 'L' && b[bl] == 'S') {
            cout << '>';
        } else if (a[al] == 'S' && b[bl] == 'L') {
            cout << '<';
        } else if (a[al] == 'S' && b[bl] == 'S') {
            if (al == bl)
                cout << '=';
            else if (al > bl)
                cout << '<';
            else
                cout << '>';
        } else if (a[al] == 'L' && b[bl] == 'L') {
            if (al == bl)
                cout << '=';
            else if (al > bl)
                cout << '>';
            else
                cout << '<';
        } else if (a[al] == 'M' && b[bl] == 'M') {
            cout << '=';
        }
        
        cout << endl;

    }
    return 0;
}