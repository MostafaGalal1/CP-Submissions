#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, k, cnt = 0;
        cin >> n >> k;
//        bool done = false;
//        vector<ll> a(n);
//
//        for (int i = 0; i < n; ++i) {
//            cin >> n;
//        }

        cout << ceil(n*1.0/k) + ((n-1)%k && k-1?1:0) << endl;
    }

    return 0;
}
