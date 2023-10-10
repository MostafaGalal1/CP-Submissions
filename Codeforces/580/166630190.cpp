#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, d, mx = 0, sum = 0;
    cin >> n >> d;
    vector<pair<ll, ll>> a(n+1), pre(n+1);

    a[0] = {0, 0}, pre[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    for (int i = 1; i <= n; ++i) {
        sum += a[i].second;
        pre[i] = {a[i].first, sum};
    }

    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(a.begin(), a.end(), make_pair(pre[i].first + d, 0ll));
        mx = max(pre[(it - a.begin() - 1)].second - pre[i-1].second, mx);
    }

    cout << mx << endl;
    return 0;
}