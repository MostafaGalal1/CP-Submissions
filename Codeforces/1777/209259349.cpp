#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

ll factorial(ll n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

ll ran(ll min, ll max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis((int)min, (int)max);

    return dis(gen);
}

// Function to calculate nCr (combination)
ll nCr(ll n, ll r) {
    ll numerator = factorial(n);
    ll denominator = factorial(r) * factorial(n - r);
    return numerator / denominator;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll cnt = 0, res = 0;
        bool xo = a[0]%2;
        
        for (int i = 1; i < n; ++i) {
            if (a[i]%2 != xo) {
                res += cnt;
                xo ^= true;
                cnt = 0;
            } else
                cnt++;
        }
        res += cnt;

        cout << res << endl;
    }

    return 0;
}
