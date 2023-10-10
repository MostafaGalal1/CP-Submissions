#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        map<ll, ll> m, res;

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }

        ll mn = 0;
        for (int i = n-1; i >= 0; --i) {
            if (a[i] - mn)
                res[i+1] = a[i] - mn;
            mn = a[i];
        }

        bool done = false;
        if ((ll)m.size() != (ll)res.size())
            done = true;
        else {
            for (auto i : m) {
                if (i.second != res[i.first]) {
                    done = true;
                    break;
                }
            }
        }

        if (!done)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}