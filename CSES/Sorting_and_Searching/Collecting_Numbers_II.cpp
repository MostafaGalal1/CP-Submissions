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
        ll n, m, x, y;
        cin >> n >> m;
        unordered_map<ll, ll> mapp;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i].first, a[i].second = i+1, mapp[i+1] = a[i].first-1;
        sort(a.begin(), a.end());

        ll cnt = 1;
        for (int i = 0; i < n-1; ++i) {
            if (a[i].second > a[i+1].second)
                cnt++;
        }

        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            cnt -= (mapp[x]?a[mapp[x]-1].second>a[mapp[x]].second?1:0:0) + (mapp[y]?a[mapp[y]-1].second>a[mapp[y]].second?1:0:0);
            cnt -= (mapp[x]<n-1?a[mapp[x]].second>a[mapp[x]+1].second?1:0:0) + (mapp[y]<n-1?a[mapp[y]].second>a[mapp[y]+1].second?1:0:0);
            if (((mapp[x]+1 == mapp[y] && a[mapp[x]].second>a[mapp[x]+1].second) || (mapp[y]+1 == mapp[x] && a[mapp[y]].second>a[mapp[y]+1].second)) || ((mapp[x]-1 == mapp[y] && a[mapp[y]].second>a[mapp[y]+1].second) || (mapp[y]-1 == mapp[x] && a[mapp[x]].second>a[mapp[x]+1].second)))
                cnt++;
            ll tm = mapp[a[mapp[x]].second];
            mapp[a[mapp[x]].second] = mapp[a[mapp[y]].second];
            mapp[a[mapp[y]].second] = tm;
            swap(a[mapp[x]].second, a[mapp[y]].second);
            cnt += (mapp[x]?a[mapp[x]-1].second>a[mapp[x]].second?1:0:0) + (mapp[y]?a[mapp[y]-1].second>a[mapp[y]].second?1:0:0);
            cnt += (mapp[x]<n-1?a[mapp[x]].second>a[mapp[x]+1].second?1:0:0) + (mapp[y]<n-1?a[mapp[y]].second>a[mapp[y]+1].second?1:0:0);
            if (((mapp[x]+1 == mapp[y] && a[mapp[x]].second>a[mapp[x]+1].second) || (mapp[y]+1 == mapp[x] && a[mapp[y]].second>a[mapp[y]+1].second)) || ((mapp[x]-1 == mapp[y] && a[mapp[y]].second>a[mapp[y]+1].second) || (mapp[y]-1 == mapp[x] && a[mapp[x]].second>a[mapp[x]+1].second)))
                cnt--;
            cout << cnt << endl;
        }
    }

    return 0;
}