#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5+5, inf = LONG_MAX, mod = 1e9+7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        string ggg;
        cin >> ggg;

        vector<ll> num = {13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        ll m = (ll)num.size();
        for (int i = 0; i < m; ++i) {
            if (to_string(num[i])[0] == ggg[0]) {
                cout << num[i] << '\n';
                break;
            }
        }
    }
    return 0;
}