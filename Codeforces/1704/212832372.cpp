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
    cin >> t;
//    t = 1;

    while (t--) {
        ll n, m;
        cin >> n >> m;
        string s, r;
        cin >> s >> r;

        if (n >= m){
            bool done = true;
            for (int i = 0; i < m-1; ++i) {
                if (s[n-1-i] != r[m-1-i]){
                    done = false;
                    break;
                }
            }
            if (done){
                bool ff = false;
                for (int i = 0; i <= n-m; ++i) {
                    if (r[0] == s[i]) {
                        cout << "YES" << endl;
                        ff = true;
                        break;
                    }
                }
                if (!ff)
                    cout << "NO" << endl;
            } else
                cout << "NO" << endl;
        } else
            cout << "NO" << endl;
    }

    return 0;
}