#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool done;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, num;
    cin >> n;
    vector<ll> v;

    for (ll i = 1; i < 10000000; i++){
        v.push_back(i*(i+1)/2);
    }

    for (ll i = 0; i < v.size(); i++){
        num = n - v[i];

        ll it = *lower_bound(v.begin(), v.end(), num);
        if (it + v[i] == n){
            cout << "YES";
            done = true;
            break;
        }
    }

    if (!done)
        cout << "NO";

    cout << endl;
    return 0;
}