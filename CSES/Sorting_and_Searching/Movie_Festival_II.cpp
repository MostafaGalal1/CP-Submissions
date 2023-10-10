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
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        multiset<ll> q;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i].second >> a[i].first;
        sort(a.begin(), a.end());

        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            auto it = q.upper_bound(a[i].second);
            if (!q.empty() && it != q.begin())
                q.erase(prev(it));
            if ((ll)q.size() < k) {
                q.insert(a[i].first);
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}