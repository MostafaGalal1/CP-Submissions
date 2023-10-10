#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll oo = INT_MAX;
const ll N = 510;

map<string, ll> mapp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, m, mn_mik = LONG_LONG_MAX, mn_joe = LONG_LONG_MAX, in_mik, in_joe;
        cin >> n;
        ll arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (i%2) {
                if (mn_joe > arr[i]) {
                    mn_joe = arr[i];
                    in_joe = i;
                }
            } else {
                if (mn_mik > arr[i]) {
                    mn_mik = arr[i];
                    in_mik = i;
                }
            }
        }

        if (n%2)
            cout << "Mike";
        else {
            if (mn_mik > mn_joe)
                cout << "Mike";
            else if (mn_mik == mn_joe) {
                if (in_mik < in_joe)
                    cout << "Joe";
                else
                    cout << "Mike";
            } else {
                cout << "Joe";
            }
        }

        cout << endl;
    }
    return 0;
}