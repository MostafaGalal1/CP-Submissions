#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, m, l, r, x;
    cin >> n >> m;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        l--, r--, x--;
        ll cl = 0;

        for (int j = l; j <= r; ++j) {
            if (a[j] < a[x])
                cl++;
        }

        if (x - l == cl)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}
