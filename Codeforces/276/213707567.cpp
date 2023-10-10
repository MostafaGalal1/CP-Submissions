#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+5;
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
    lazy(ind, sl, sr);
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return query(ind*2, sl, mid, ql, qr) + query(ind*2+1, mid+1, sr, ql, qr);
}

int main() {
    fast();
    ll n, q, ql, qr, nu;
    cin >> n >> q;

    vector<ll> aux;
    for (ll i = 1; i <= n; ++i)
        arr[i] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> nu;
        aux.push_back(nu);
    }

    build(1, 0, n);
    vector<pair<ll, ll>> qu, qq;

    for (int i = 0; i < q; ++i) {
        cin >> ql >> qr;
        qu.emplace_back(ql, qr);
        update(1, 0, n, ql, qr, 1);
    }

    for (int i = 1; i <= n; ++i)
        qq.emplace_back(query(1, 0, n, i, i), i);

    sort(qq.rbegin(), qq.rend());
    sort(aux.rbegin(), aux.rend());

    for (int i = 1; i <= n; ++i)
        arr[qq[i-1].second] = aux[i-1];
    build(1, 0, n);

    ll res = 0;
    for (int i = 0; i < q; ++i) {
        ql = qu[i].first;
        qr = qu[i].second;
        res += query(1, 0, n, ql, qr);
    }

    cout << res << endl;
    return 0;
}