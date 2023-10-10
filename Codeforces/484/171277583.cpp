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

    for (int i = 0; i < t; ++i) {
        ll l, r;
        ll n, m;
        
        cin >> l >> r;

        m = (ll)log2(r + 1);
        
        n = (ll)pow(2, m) - 1;

        while (n < l && m){
            while (n + (ll)pow(2, m) > r && m)
                m--;
            n += (ll)  pow(2, m);
        }

        cout << n << endl;
    }
    return 0;
}