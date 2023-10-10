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

    while (t --> 0){
        ll n, m;
        cin >> n >> m;

        cout << (n%2 == m%2? "Tonya":"Burenka") << endl;
    }
    return 0;
}