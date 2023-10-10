#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;

    return true;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);

        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (isPrime(sum)) {
            ll ind = 0;
            for (int i = 0; i < n; ++i) {
                if (!isPrime(sum - a[i])){
                    ind = i;
                    break;
                }
            }
            cout << n - 1 << endl;
            for (int i = 0; i < n; ++i) {
                if (i != ind)
                    cout << i + 1 << " ";
            }
        } else {
            cout << n << endl;
            for (int i = 0; i < n; ++i)
                cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}