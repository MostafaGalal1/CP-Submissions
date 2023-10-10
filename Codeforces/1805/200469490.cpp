#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 3e5 + 10, inf = INT_MAX;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        int n, m;
        cin >> n >> m;
        vector<ll> lines;
        vector<tuple<ll, ll, ll>> parabolas(m);

        for (int i = 0; i < n; i++) {
            ll b;
            cin >> b;
            lines.push_back(b);
        }

        std::sort(lines.begin(), lines.end());

        for (int i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            ll k1 = lines[0], k2 = lines[n-1];
            auto it = lower_bound(lines.begin(), lines.end(), b);
            if (it != lines.end()) k1 = *it;
            if (it != lines.begin()){
                it = prev(it);
                k2 = *it;
            }

            if ((b - k1) * (b - k1) < 4 * a * c) {
                cout << "YES\n" << k1 <<endl;
                continue;
            }

            if ((b - k2) * (b - k2) < 4 * a * c) {
                cout << "YES\n" << k2 << endl;
                continue;
            }

            cout << "NO" << endl;
        }
        cout << endl;
    }
    return 0;
}