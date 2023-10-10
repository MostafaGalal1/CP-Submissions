#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, d;
    cin>> a >> b >> c >> d;

    cout << min(a * c, a / b * d + (a / b * b < a ? min((a - a / b * b) * c, d):0)) << endl;
    return 0;
}