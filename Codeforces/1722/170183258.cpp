#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 4e5 + 10;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        string r1, r2;
        cin >> r1 >> r2;

        for(int i = 0;i < n;i++){
            if(r1[i] == 'G')
                r1[i] = 'B';
        }
        for(int i = 0;i < n;i++) {
            if (r2[i] == 'G')
                r2[i] = 'B';
        }
        cout << (r1 == r2 ? "YES" : "NO") << endl;
    }

    return 0;
}