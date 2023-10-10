#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, num, sum = 0;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
        arr[i] = num;
    }

    sort(arr, arr+n);
    ll med = sum / n;

    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i] - med;
    }

    if (!sum)
        cout << n;
    else
        cout << n-1;

    cout << endl;
    return 0;
}