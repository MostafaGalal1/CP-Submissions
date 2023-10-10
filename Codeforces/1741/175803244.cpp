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
        ll n;
        cin >> n;

        if (n == 3) {
            cout << -1 << endl;
            continue;
        }

        if (n%2){
            for (int i = n; i > n/2 + 1; --i) {
                cout << i << ' ';
            }
            for (int i = 1; i <= n/2 + 1; ++i) {
                cout << i << ' ';
            }
            cout << endl;
        } else {
            for (int i = n; i > 0; --i) {
                cout << i << ' ';
            }
            cout << endl;
        }

    }
    return 0;
}