#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n, m, x, y, nu;
    cin >> n >> m >> x >> y;
    vector<ll> a(n);
    multiset<pair<ll, ll>> b;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> nu;
        b.insert({nu, i+1});
    }

    vector<pair<ll, ll>> res;
    for (int i = 0; i < n && !b.empty(); ++i) {
        auto it = b.lower_bound({a[i] - x, 0});
        if (it != b.end() && (*it).first <= a[i] + y){
            res.push_back({i+1, (*it).second});
            b.erase(it);
        }
    }

    cout << (ll)res.size() << endl;
    for (int i = 0; i < (ll)res.size(); ++i) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}