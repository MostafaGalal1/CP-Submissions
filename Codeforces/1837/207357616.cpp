#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t, tt;
    cin >> t;

    bool hj = false;
    tt= t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << (n%k? 1:2) << endl;
        cout << (n%k? to_string(n) : to_string(n-1) + " " + to_string(1)) << endl;
    }

    return 0;
}
