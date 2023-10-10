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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        bool xo = true, done = false;
        vector<map<ll, ll>> c(n+m-1);
        ll cnt = 0;
        for (ll i = 0; i < n+m-1; ++i) {
            for (int j = 0; j+cnt < min(i+1, m); ++j)
                c[i][a[min(i, n-1)-j][(xo ? 0 : cnt) + j]]++;
            if (i == n-1)
                xo = false;
            if (!xo)
                cnt++;
        }

        cnt = 0;
        xo = true;
        for (ll i = 0; i < n+m-1; ++i) {
            for (int j = 0; j+cnt < min(i+1, m); ++j) {
                c[i][b[min(i, n - 1) - j][(xo ? 0 : cnt) + j]]--;
                if (c[i][b[min(i, n - 1) - j][(xo ? 0 : cnt) + j]] == 0)
                    c[i].erase(b[min(i, n - 1) - j][(xo ? 0 : cnt) + j]);
            }
            if (!c[i].empty()){
                done = true;
                break;
            }
            if (i == n-1)
                xo = false;
            if (!xo)
                cnt++;
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}