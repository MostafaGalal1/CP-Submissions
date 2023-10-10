#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m1 = 0, m2 = 0;
        cin >> n;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i])
                a[i] ^= b[i], b[i] ^= a[i], a[i] ^= b[i];
        }

        for (int i = 0; i < n; ++i) {
            m1 = max(m1, a[i]);
            m2 = max(m2, b[i]);
        }

        cout << m1 * m2 << endl;
    }

    cout << endl;

    return 0;
}