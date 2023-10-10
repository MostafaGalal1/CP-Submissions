#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll arr[N], seg[4*N];
pair<ll, ll> laz[4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void build (ll ind, ll sl, ll sr) {
    laz[ind] = {0, 0};
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
    if (laz[ind].second != 0) {
        seg[ind] += (laz[ind].second * (sr * sr - (sl - 1) * (sl - 1) + sr - (sl - 1)) - 2 * (sr - sl + 1) * (laz[ind].first - laz[ind].second))/2;
        if (sl != sr) {
            laz[ind * 2] = {laz[ind*2].first+laz[ind].first, laz[ind*2].second+laz[ind].second};
            laz[ind*2+1] = {laz[ind*2+1].first+laz[ind].first, laz[ind*2+1].second+laz[ind].second};
        }
        laz[ind] = {0, 0};
    }
}

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll st) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] += (sr * sr - (sl - 1) * (sl - 1) - 2 * (sr - sl + 1) * (st - 1) + sr - (sl - 1))/2;
        if (sl != sr) {
            laz[ind*2] = {laz[ind*2].first + st, laz[ind*2].second + 1};
            laz[ind*2+1] = {laz[ind*2+1].first + st, laz[ind*2+1].second + 1};
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, st);
    update(ind*2+1, mid+1, sr, ql, qr, st);
    seg[ind] = seg[ind*2] + seg[ind*2+1];
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return 0;
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return query(ind*2, sl, mid, ql, qr) + query(ind*2+1, mid+1, sr, ql, qr);
}

int main() {
    fast();
    ll n, q, o, ql, qr;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 1, n);

    while (q --> 0) {
        cin >> o >> ql >> qr;
        if (o == 1)
            update(1, 1, n, ql, qr, ql);
        else
            cout << query(1, 1, n, ql, qr) << endl;
    }

    return 0;
}