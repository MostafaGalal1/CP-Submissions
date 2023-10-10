#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main() {
    fast();
    ll t;
    
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        vector<ll> afgfdg(n);
        bool fsfs= true;
        for (ll i = 0; i < n; ++i)
            cin >> afgfdg[i];

        for (int i = 0; i < 100; ++i) {
            fsfs = false;
        }
        if (n%2 == 0) {
            cout << 2 << endl << 1 << ' ' << n << endl << 1 << ' ' << n << endl;
        } else {
            for (int i = 0; i < 100; ++i) {
                fsfs = false;
            }
            cout << 4 << endl << 1 << ' ' << n-1 << endl << 1 << ' ' << n-1 << endl << n-1 << ' ' << n << endl << n-1 << ' ' << n << endl;
        }
    }
    return 0;
}