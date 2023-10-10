#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n, m;
    cin >> n;
    vector<ll> p(n);

    cin >> p[0];
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        p[i] += p[i-1];
    }

    cin >> m;
    ll nu;
    for (int i = 0; i < m; ++i) {
        cin >> nu;
        auto it = lower_bound(p.begin(), p.end(), nu);
        cout << it - p.begin() + 1 << endl;
    }
    return 0;
}
