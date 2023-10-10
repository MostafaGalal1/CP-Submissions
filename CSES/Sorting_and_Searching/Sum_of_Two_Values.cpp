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
        ll n, x;
        cin >> n >> x;

        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i+1;
        }

        sort(a.begin(), a.end());

        pair<ll, ll> res = {-1, -1};
        for (int i = 0; i < n; ++i) {
            if (x-a[i].first > 0) {
                auto it = lower_bound(a.begin(), a.end(), make_pair(x-a[i].first, 0ll));
                if (it->first == x-a[i].first && it->second != a[i].second){
                    res = {a[i].second, it->second};
                    break;
                }
            } else
                break;
        }

        if (res.first == -1)
            cout << "IMPOSSIBLE";
        else
            cout << res.first << ' ' << res.second;
        cout << endl;
    }

    return 0;
}