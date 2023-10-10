#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 110, oo = INT_MAX;
ll arr[N][N];

int main() {
    ll t = 1;

    while (true) {
        bool first = true;
        ll n, u, v, num = 1;
        double tot = 0;
        map<ll, ll> mapp;

        mapp.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = oo;
            }
        }

        while(cin >> u >> v) {
            if (first && !(u || v))
                return 0;
            else if (!(u || v))
                break;
            else
                first = false;

            if (!mapp[u])
                mapp[u] = num++;
            if (!mapp[v])
                mapp[v] = num++;

            arr[mapp[u]-1][mapp[v]-1] = 1;
        }

        n = (ll)mapp.size();

        for (ll k = 0; k < n; ++k) {
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                tot += (double)arr[i][j];;
            }
        }

        cout << "Case " << t << ": average length between pages = " << fixed << setprecision(3) << tot / (double)(n * (n-1)) << " clicks" << endl;
        t++;
    }
}