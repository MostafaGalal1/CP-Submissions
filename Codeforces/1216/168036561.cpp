#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 3010;
unordered_map<int, int> mapp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i-1].first;
        arr[i-1].second = i;
    }

    sort(arr.rbegin(), arr.rend());

    for (int i = 0; i < n; ++i)
        sum += arr[i].first * i + 1;

    cout << sum << endl;

    for (int i = 0; i < n; ++i)
        cout << arr[i].second << ' ';

    cout << endl;

    return 0;
}