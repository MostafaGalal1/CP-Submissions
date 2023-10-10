#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, m, cnt;
    cin >> n >> m;
    cnt = n;
    ll arr[n];
    m %= n;

    for (ll i = 0; i < n; ++i){
        cin >> arr[i];
    }

    ll i = m-1;
    while(cnt --> 0){
        i++;
        i %= n;
        cout << arr[i] << " ";
    }
    cout << endl;
}