#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n, b;
    cin >> n >> b;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll res = b;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            res = max(res, b/a[i] * a[j] + b%a[i]);
        }
    }

    cout << res << endl;
    return 0;
}