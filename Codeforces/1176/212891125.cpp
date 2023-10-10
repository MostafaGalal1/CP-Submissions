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

int firstdiv(ll n) {
    ll g = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            g = n/i;
            break;
        }
    }
    return g;
}

void sieve(ll limit, unordered_map<ll, ll>& mapp) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    ll cnt = 1;
    for (ll i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            if (isPrime[cnt])
                mapp[i] = cnt;
            cnt++;
            for (ll j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = (ll)sqrt(limit); i <= limit; ++i) {
        if (isPrime[i]) {
            if (isPrime[cnt])
                mapp[i] = cnt;
            cnt++;
        }
    }
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, nu;
        cin >> n;
        multiset<ll> a;
        unordered_map<ll, ll> mapp;
        sieve(2750131, mapp);

        for (int i = 0; i < 2*n; ++i) {
            cin >> nu;
            a.insert(nu);
        }

        vector<ll> res;
        for (int i = 0; i < n; ++i) {
            ll num = *prev(a.end());
            if (mapp[num]){
                auto it = a.lower_bound(mapp[num]);
                res.push_back(mapp[num]);
                a.erase(prev(a.end()));
                a.erase(it);
            } else {
                ll dv = firstdiv(num);
                auto it = a.lower_bound(dv);
                res.push_back(num);
                a.erase(prev(a.end()));
                a.erase(it);
            }
        }

        for (int i = 0; i < n; ++i)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}