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
        ll n, m, a, b;
        cin >> n >> m >> a >> b;

        ll d = 1;
        for (int i = 1; i <= m; ++i) {
            if ((i * n) % m == 0) {
                d = i;
                break;
            }
        }
        
        vector<vector<char>> v(n, vector<char>(m, '0'));
        if (a * n == b * m){
            cout << "YES\n";
            ll ad = 0;
            for (int j = 0; j < n; ++j) {
                for (int k = ad; k < a+ad; ++k)
                    v[j][k%m] = '1';
                ad += d;
            }
            for (int l = 0; l < n; ++l) {
                for (int i = 0; i < m; ++i)
                    cout << v[l][i];
                cout << "\n";
            }
        } else
            cout << "NO\n";

    }
    return 0;
}