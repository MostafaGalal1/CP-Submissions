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

    while (t --> 0){
        vector<ll> ve;
        bool done = false;
        ll n, l, r;
        cin >> n >> l >> r;

        for (ll i = 1; i <= n; ++i) {
            if (((l-1)/i+1)*i > r) {
                cout << "NO";
                done = true;
                break;
            }
            ve.push_back(((l-1)/i+1)*i);
        }

        if (!done){
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                cout << ve[i] << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}