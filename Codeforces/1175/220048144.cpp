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
        vector<ll> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        ll mn = LONG_LONG_MAX, mni;
        for (int i = 0; i < n-k; ++i) {
            if ((a[i + k] - a[i] + 1) / 2 < mn)
                mn = (a[i + k] - a[i] + 1) / 2, mni = a[i] + (a[i + k] - a[i] + 1) / 2;
        }

        cout << mni << endl;
    }
    return 0;
}