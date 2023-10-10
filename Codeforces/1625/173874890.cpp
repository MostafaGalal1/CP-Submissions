#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

bool cmp (pair<ll, ll> a, pair<ll, ll> b){
    return a.first - a.second < b.first - b.second;
}


int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a(n), v;

        for (int i = 0; i < n; ++i)
            cin >> a[i].first, a[i].second = i;

        sort(a.begin(), a.end());

        for (int i = 0; i < n-1; ++i) {
            if (a[i].first == a[i+1].first) {
                v.push_back({a[i+1].second, a[i].second});
            }
        }

        sort(v.begin(), v.end(), cmp);

        if (v.empty())
            cout << -1;
        else
            cout << v[0].second + n - v[0].first;
        cout << endl;
    }

    return 0;
}