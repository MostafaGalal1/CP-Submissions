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
    ll mod = 1e9+7;
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll fc = 1;
        for (int i = 1; i <= n; ++i) {
            fc *= i;
            fc %= mod;
        }
        cout << (((fc*n)%mod)*(n-1))%mod << endl;
    }

    return 0;
}
