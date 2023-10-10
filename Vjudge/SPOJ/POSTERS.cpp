#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5;
ll arr[N], seg[4*N], laz[4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void build (ll ind, ll sl, ll sr) {
    if (sl == sr){
        seg[ind] = arr[sl];
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    build(ind*2, sl, mid);
    build(ind*2+1, mid+1, sr);
    seg[ind] = max(seg[ind*2], seg[ind*2+1]);
}

void lazy (ll ind, ll sl, ll sr) {
    if (laz[ind] != 0) {
        seg[ind] = laz[ind];
        if (sl != sr) {
            laz[ind * 2] = laz[ind];
            laz[ind*2+1] = laz[ind];
        }
        laz[ind] = 0;
    }
}

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    lazy(ind, sl, sr);
    if (ql <= sl && qr >= sr) {
        seg[ind] = val;
        if (sl != sr) {
            laz[ind*2] = val;
            laz[ind*2+1] = val;
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = max(seg[ind*2], seg[ind*2+1]);
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return LONG_LONG_MIN;
    lazy(ind, sl, sr);
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return max(query(ind*2, sl, mid, ql, qr), query(ind*2+1, mid+1, sr, ql, qr));
}

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, ql, qr, x, y, cnt = 1;
        cin >> n;

        map<ll, ll> mapp;
        set<ll> v;
        vector<pair<ll, ll>> a;

        for (ll i = 1; i <= n; ++i) {
            cin >> x >> y;
            a.emplace_back(x, y);
            v.insert(x);
            v.insert(y);
        }

        for (ll m: v)
            mapp[m] = cnt++;

        build(1, 0, mapp[*prev(v.end())]);

        cnt = 1;
        for (int i = 0; i < n; ++i) {
            ql = a[i].first, qr = a[i].second;
            update(1, 0, mapp[*prev(v.end())], mapp[ql], mapp[qr], cnt++);
        }

        set<ll> res;
        for (int i = 1; i <= mapp[*prev(v.end())]; ++i)
            res.insert(query(1, 0, mapp[*prev(v.end())], i, i));

        cout << (ll)res.size() << endl;
    }
    return 0;
}