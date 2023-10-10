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

    while(t -- > 0) {
        ll n, k;
        cin >> n >> k;

        if (k % 4 == 0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (k % 2){
                for (int i = 1; i <= n; i += 2) {
                    cout << i << ' ' << i + 1 << endl;
                }
            } else {
                for (int i = 3; i <= n; i += 4) {
                    cout << i << ' ' << i + 1 << endl;
                }
                for (int i = 2; i <= n; i += 4) {
                    cout << i << ' ' << i - 1 << endl;
                }
            }
        }
    }
    return 0;
}