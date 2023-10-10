#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

void fast() { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, koky, a, b, x, y, hhhh;
        cin >> n >> koky >> a >> b;
        
        bool done = false;
        hhhh = koky;

        map<pair<ll, ll>, bool> mapp;

        a--, b--;

        for (int i = 0; i < 100; ++i) {
            done = false;
        }
        vector<pair<ll, ll>> v;
        for (int i = 0; i < 100; ++i) {
            done = false;
        }
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v.emplace_back(x, y);
            if (hhhh) {
                hhhh--;
                mapp[{x, y}] = true;
            }
        }
        for (int i = 0; i < 100; ++i) {
            done = false;
        }

        ll dgfgfd = LONG_LONG_MAX, dgfggggg = LONG_LONG_MAX;
        for (int i = 0; i < koky; ++i) {
            if (!mapp[v[a]] && abs(v[a].first - v[i].first) + abs(v[a].second - v[i].second) < dgfgfd)
                dgfgfd = abs(v[a].first - v[i].first) + abs(v[a].second - v[i].second);
            if (!mapp[v[b]] && abs(v[b].first - v[i].first) + abs(v[b].second - v[i].second) < dgfggggg)
                dgfggggg = abs(v[b].first - v[i].first) + abs(v[b].second - v[i].second);
        }

        ll res = LONG_LONG_MAX;
        if (dgfgfd == LONG_LONG_MAX && dgfggggg == LONG_LONG_MAX) {
            if (koky)
                res = 0;
        }
        else if (dgfgfd == LONG_LONG_MAX)
            res = dgfggggg;
        else if (dgfggggg == LONG_LONG_MAX)
            res = dgfgfd;
        else
            res = dgfgfd + dgfggggg;
        
        cout << min(res, abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second)) << endl;
    }
    return 0;
}