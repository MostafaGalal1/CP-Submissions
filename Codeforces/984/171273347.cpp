#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    vector<ll> a(t);

    for (int i = 0; i < t; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << a[t%2? t/2:t/2-1] << endl;
    return 0;
}