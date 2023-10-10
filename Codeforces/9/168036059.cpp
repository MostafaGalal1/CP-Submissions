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

    int n, m, div;
    cin >> n >> m;

    div = __gcd((6 - max(n, m) + 1), 6);
    cout << (6 - max(n, m) + 1) / div << "/" << 6 / div << endl;
    return 0;
}