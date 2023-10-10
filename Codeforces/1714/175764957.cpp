#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, cnt = 0, sz;
        cin >> n;

        vector<ll> ve(n);
        set<ll> se;

        for (int i = 0; i < n; ++i) {
            cin >> ve[i];
        }

        for (int i = n-1; i >= 0; --i) {
            sz = se.size();
            se.insert(ve[i]);
            if (se.size() == sz){
                cnt = n - sz;
                break;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}