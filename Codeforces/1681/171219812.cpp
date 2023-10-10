#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m, num , sum = 0;
        cin >> n;
        vector<ll> a(n);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cin >> m;

        for (ll i = 0; i < m; ++i) {
            cin >> num;
            sum += num;
        }

        cout << a[sum%n] << endl;
    }

    return 0;
}