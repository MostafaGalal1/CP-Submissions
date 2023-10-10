#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1010, inf = 99999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b, odd = 0, even = 0, cnt = 0;
    cin >> n >> b;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> v;
    for (int i = 0; i < n-1; ++i) {
        if (arr[i]%2)
            odd++;
        else
            even++;
        if (even == odd && even != 0)
            v.push_back(abs(arr[i+1] - arr[i]));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() && b > 0; ++i) {
        if (b - v[i] < 0)
            break;
        b -= v[i];
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}