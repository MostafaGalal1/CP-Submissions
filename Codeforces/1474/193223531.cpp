#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<bool> sieve(ll n) {
    vector<bool> prime(n+1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}

int main() {
    fast();

    vector<bool> p = sieve(1e5);

    ll t;
    cin >> t;

    while (t-- > 0) {
        ll n, n1 = 0, n2 = 0;
        cin >> n;

        for (ll i = n + 1; i <= 1e5; ++i) {
            if (p[i]) {
                n1 = i;
                break;
            }
        }

        for (ll i = n1 + n; i <= 1e5; ++i) {
            if (p[i]) {
                n2 = i;
                break;
            }
        }

        cout << n1 * n2 << endl;
    }

    return 0;
}
