#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    if (m - n > 5)
        cout << 0;
    else {
        ll fact = 1;
        for (int i = 0; i < m - n; ++i) {
            fact *= (m-i)%10;
            fact %= 10;
        }
        cout << fact;
    }
    return 0;
}