#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n;
    cin >> n;
    vector<ll> res(n), mx(n, 0);
    vector<pair<ll, ll>> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        mx[i] = max(i?mx[i-1]:0ll, a[i].second);
        res[a[i].second] = mx[i] - a[i].second - 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}