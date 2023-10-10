#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), diff(n-1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
        diff[i] = a[i] - a[i+1];
    }

    sort(diff.begin(), diff.end());

    ll res = a[n-1] - a[0];
    for (int i = 0; i < k - 1; ++i) {
        res += diff[i];
    }

    cout << res << endl;
    return 0;
}