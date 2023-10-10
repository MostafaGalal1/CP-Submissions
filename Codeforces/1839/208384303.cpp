#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, x, y;
        cin >> n;
        map<ll, priority_queue<ll>> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            mapp[x].push(y);
        }

        ll res = 0;
        for (auto & m : mapp){
            ll cnt = 0;
            while (!m.second.empty() && cnt < m.first) {
                res += m.second.top();
                m.second.pop();
                cnt++;
            }
        }

        cout << res << endl;
    }

    return 0;
}
