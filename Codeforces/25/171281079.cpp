#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (s.length() < 4)
        cout << s;
    else {
        for (int i = 0; i < n; ++i) {
            cout << s[i];
            if ((i+1)%2 == 0 && i < n-2)
                cout << '-';
        }
    }
    return 0;
}