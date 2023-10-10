#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 3e5+5;
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
    seg[ind] = seg[ind*2] + seg[ind*2+1];
}

void lazy (ll ind, ll sl, ll sr) {
    if (laz[ind] != 0) {
        seg[ind] += (sr - sl + 1) * laz[ind];
        if (sl != sr) {
            laz[ind * 2] += laz[ind];
            laz[ind*2+1] += laz[ind];
        }
        laz[ind] = 0;
    }
}

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    lazy(ind, sl, sr);
    if (ql <= sl && qr >= sr) {
        seg[ind] += (sr - sl + 1) * val;
        if (sl != sr) {
            laz[ind*2] += val;
            laz[ind*2+1] += val;
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = seg[ind*2] + seg[ind*2+1];
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return 0;
//    lazy(ind, sl, sr);
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return query(ind*2, sl, mid, ql, qr) + query(ind*2+1, mid+1, sr, ql, qr);
}

int main() {
    fast();
    ll n, q, ql, qr, nu;
    cin >> n;

    vector<ll> a(n+1), p(1e6+3, -1);
    set<pair<pair<ll, ll>, ll>> s;
    for (ll i = 1; i <= n; ++i)
        arr[i] = 0, cin >> a[i];

    build(1, 0, n);

    cin >> q;
    vector<ll> res(q);
    for (int i = 0; i < q; ++i) {
        cin >> ql >> qr;
        s.insert({{qr, ql}, i});
    }

    for (int i = 1; i <= n; ++i) {
        if (p[a[i]] != -1)
            update(1, 0, n, p[a[i]], p[a[i]], -1);
        p[a[i]] = i;
        update(1, 0, n, i, i, 1);
        auto it = s.lower_bound({{i, 0}, 0});
        while (it != s.end() && it->first.first == i) {
            res[it->second] = query(1, 0, n, it->first.second, i);
            it = next(it);
        }
    }
    for (ll r : res)
        cout << r << endl;
    return 0;
}