#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        if (n == 3)
            cout << 2 << ' ' << 1 << ' ' << 3;
        else if (n%4 == 0 || n%4 == 1) {
            for (ll i = 0; i < n-1; i += 2) {
                cout << i + 4 << ' ' << i + 5 << ' ';
            }
            if (n%2)
                cout << 0;
        } else if (n%4 == 2 || n%4 == 3) {
            ll e = 0, o = 0;
            for (ll i = 0; i < n - 4 - (n%2)? 1:0; i += 2) {
                cout << i + 6 << ' ' << i + n/2 + 6 << ' ';
                e ^= i+6;
                o ^= i + n/2 + 6;
            }
            cout << (ll)pow(2, 30) + 1 << ' ' << (ll)pow(2, 30) + 6 << ' ';
            e ^= (ll)pow(2, 30)+1;
            o ^= (ll)pow(2, 30)+6;
            cout << e << ' ' << o << ' ';
            if (n%2)
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}