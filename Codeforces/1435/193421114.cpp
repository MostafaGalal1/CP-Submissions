#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll n, m, h, nu;
        cin >> n >> m;
        vector<ll> s(n), x(n);
        map<ll, vector<ll>> a;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> nu;
                if (!j)
                    h = nu;
                a[h].push_back(nu);
            }
        }

        for (int i = 0; i < m; ++i) {
            x.clear();
            for (int j = 0; j < n; ++j) {
                cin >> x[j];
            }
            if (!a[x[0]].empty()){
                for (int j = 0; j < n; ++j) {
                    s[j] = x[j];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[s[i]][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
