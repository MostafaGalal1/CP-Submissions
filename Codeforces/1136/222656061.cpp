#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

const ll N = 2e6+5, inf = LONG_MAX, mod = 998244353;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<int> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> v;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            if (i * i <= n) {
                v.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                    isPrime[j] = false;
            } else
                v.push_back(i);
        }
    }
    return v;
}

int main() {
    fast();
    int t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, l, r;
        cin >> n;

        vector<ll> a(n+1);
        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            a[i] = l;
        }
        a[n] = r+1;

        ll q;
        cin >> q;
        cout << n - (upper_bound(a.begin(), a.end(), q) - a.begin()) + 1 << endl;
    }
    return 0;
}