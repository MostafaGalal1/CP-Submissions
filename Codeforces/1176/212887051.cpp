#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<int> primeFactorization(ll n, map<ll, ll>& mapp) {
    vector<int> factors;
    while (n % 2 == 0) {
        mapp[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mapp[i]++;
            n /= i;
        }
    }
    if (n > 2)
        mapp[n]++;
    return factors;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n;
        cin >> n;

        if (n == 1){
            cout << 0 << endl;
            continue;
        }

        map<ll, ll> mapp;
        primeFactorization(n, mapp);

        ll num = prev(mapp.end())->first;
        if (num != 5 && num != 3 && num != 2)
            cout << -1;
        else
            cout << mapp[2] + 2*mapp[3] + 3*mapp[5];
        cout << endl;
    }

    return 0;
}