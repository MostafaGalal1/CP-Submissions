#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

        ll n;
        cin >> n;

        cout << (n%2? 0:(ll)pow(2, n/2)) << endl;

    return 0;
}