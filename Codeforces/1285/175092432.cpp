#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> ve;

    pair<ll, ll> p;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0)
            if (__gcd(i, n/i) == 1)
                p.first = i, p.second = n/i;
    }

    cout << p.first << ' ' << p.second << endl;
}