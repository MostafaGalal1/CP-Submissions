#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main() {
    fast();

    ll n, d, cnt = 0, wins = 0;
    cin >> n >> d;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (ll i = n-1; i >= 0; --i) {
        cnt++;
        if (cnt + d/a[i] <= n){
            cnt += d/a[i];
        } else
            break;
        wins++;
    }

    cout << wins << endl;

    return 0;
}