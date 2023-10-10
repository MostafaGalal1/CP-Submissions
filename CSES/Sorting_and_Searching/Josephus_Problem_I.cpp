#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        map<ll, bool> m;
        for (int i = 1; i <= n; ++i)
            m[i] = true;

        ll cnt = 0;
        bool xo = false;
        while (cnt < n) {
            for (auto &mm: m) {
                if (mm.second) {
                    if (xo) {
                        cout << mm.first << ' ';
                        mm.second = false;
                        cnt++;
                    }
                    xo ^= true;
                }
            }
        }

        cout << endl;
    }

    return 0;
}