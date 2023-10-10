#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;

    double d = sqrt(x * x + y * y);

    if (x == 0 || y == 0){
        cout << "black";
    } else if ((x < 0 && y < 0) || (x > 0 && y > 0)){
        if (d == floor(d)){
            cout << "black";
        } else {
            if ((ll) floor(d) % 2)
                cout << "white";
            else
                cout << "black";
        }
    } else if ((x > 0 && y < 0) || (x < 0 && y > 0)){
        if (d == floor(d)){
            cout << "black";
        } else {
            if ((ll)floor(d) % 2)
                cout << "black";
            else
                cout << "white";
        }
    }
    cout << endl;

    return 0;
}