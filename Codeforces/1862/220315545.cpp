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

    while (t--) {
        ll n, m;
        cin >> n >> m;
        bool done = false;
        vector<vector<char>> a(n, vector<char>(m));

        vector<bool> v(4, false);
        vector<char> ch = {'v', 'i', 'k', 'a'};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        ll cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j][i] == ch[cnt]) {
                    v[cnt] = true;
                    cnt++;
                    break;
                }
            }
        }

        if (v[0] && v[1] && v[2] && v[3])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}