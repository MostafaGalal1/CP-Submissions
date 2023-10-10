#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, m, num, cnt = 0;
        cin >> n >> m;
        map<ll, ll> mapp;

        for (int i = 0; i < n; ++i) {
           cin >> num;
           mapp[num]++;
        }

        for(auto & i : mapp){
            if (i.second < m)
                cnt += i.second;
            else
                cnt += m;
        }

        cout << cnt << endl;
    }

    return 0;
}