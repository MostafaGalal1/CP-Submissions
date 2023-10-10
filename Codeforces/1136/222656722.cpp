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
        ll n, k;
        cin >> n >> k;
        k = min(k, n-k+1);
        cout << 3*n + k-1 << endl;
    }
    return 0;
}