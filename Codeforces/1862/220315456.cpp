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
        vector<ll> a(n), res;

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        res.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i-1])
                res.push_back(a[i]);
            else {
                res.push_back(a[i]);
                res.push_back(a[i]);
            }
        }

        cout << (ll)res.size() << endl;
        for (auto &i : res) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}