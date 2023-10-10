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

    while (t --> 0) {
        ll n, k;
        cin >> n >> k;

        if (n == 1 && k == 1) {
            cout << 0 << endl;
            continue;
        }

        vector<ll> res;
        for (int i = (k+1)/2; i <= n; ++i) {
            if (i == k)
                continue;
            res.push_back(i);
        }

        cout << (ll)res.size() << endl;
        for (auto &i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}