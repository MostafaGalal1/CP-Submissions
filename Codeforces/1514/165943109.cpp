#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t-- > 0){
        int n, k;
        ll fact = 1;
        cin >> n >> k;

        for (int i = 0; i < k; i++) {
            fact *= n;
            fact %= (ll)(1e9 + 7);
        }

        cout << (fact) % (ll)(1e9 + 7) << endl;
    }

    return 0;
}