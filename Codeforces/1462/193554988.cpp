#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll n, l, r;
        cin >> n;
        vector<pair<ll, ll>> s, p;
        map<pair<ll, ll>, ll> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            p.emplace_back(r, l);
            s.emplace_back(l, r);
        }

        sort(s.begin(), s.end());
        sort(p.begin(), p.end());

        for (auto & m : s){
            auto pil = lower_bound(p.begin(), p.end(), make_pair(m.first, 1ll));
            auto pir = upper_bound(p.begin(), p.end(), make_pair(LONG_LONG_MAX, LONG_LONG_MAX));
            auto sil = lower_bound(s.begin(), s.end(), make_pair(m.second + 1, m.second + 1));
            auto sir = upper_bound(s.begin(), s.end(), make_pair(LONG_LONG_MAX, LONG_LONG_MAX));
            mapp[m] = (pir - pil) - (sir - sil);
        }

        cout << n - max_element(mapp.begin(), mapp.end(), [](const auto &x, const auto &y) {
            return x.second < y.second;
        })->second << endl;
    }

    return 0;
}
