#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    for (ll h = 1; h <= t; h++) {
        unordered_map<ll, ll> mapp;
        ll n, m, a, b, num, mn = LONG_LONG_MAX;
        cin >> n >> m;
        ll arr[n];
        pair<ll, ll> p[m];

        for (ll i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (ll i = 0; i < m; ++i) {
            cin >> a >> b;
            a--;
            b--;
            p[i].first = a;
            p[i].second = b;
            mapp[a]++;
            mapp[b]++;
        }

        if (m%2 == 0){
            cout << 0 << endl;
        } else {
            for (ll i = 0; i < m; ++i) {
                if (mapp[p[i].first]%2 == 0 && mapp[p[i].second]%2 == 0){
                    num = arr[p[i].first] + arr[p[i].second];
                } else {
                    ll n1 = LONG_LONG_MAX, n2 = LONG_LONG_MAX;
                    if (mapp[p[i].first] % 2 == 1) {
                        n1 = arr[p[i].first];
                    }
                    if (mapp[p[i].second] % 2 == 1) {
                        n2 = arr[p[i].second];
                    }

                    num = min(n1, n2);
                }
                if (num < mn) {
                    mn = num;
                }
            }

            cout << mn << endl;
        }
    }
    return 0;
}