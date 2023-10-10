#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

        ll n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    ll gc = 0;
    for (int i = 1; i < n; ++i) {
        gc = __gcd(gc, a[i] - a[0]);
    }

    for (int i = 0; i < m; ++i) {
        cout << __gcd(gc, a[0] + b[i]) << ' ';
    }

    return 0;
}