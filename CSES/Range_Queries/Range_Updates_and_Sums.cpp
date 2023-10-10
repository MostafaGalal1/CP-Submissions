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
    if (laz[ind].first == 1) {
        seg[ind] += (sr - sl + 1) * laz[ind].second;
        if (sl != sr) {
            laz[ind*2] = {(laz[ind*2].first==2?2:1), laz[ind*2].second+laz[ind].second};
            laz[ind*2+1] = {(laz[ind*2+1].first==2?2:1), laz[ind*2+1].second+laz[ind].second};
        }
    } else if (laz[ind].first == 2) {
        seg[ind] = (sr - sl + 1) * laz[ind].second;
        if (sl != sr) {
            laz[ind * 2] = {2, laz[ind].second};
            laz[ind * 2 + 1] = {2, laz[ind].second};
        }
    }
    laz[ind] = {0, 0};
}

void updateVal(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] = (sr - sl + 1) * val;
        if (sl != sr) {
            laz[ind*2] = {2, val};
            laz[ind*2+1] = {2, val};
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    updateVal(ind*2, sl, mid, ql, qr, val);
    updateVal(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = seg[ind*2] + seg[ind*2+1];
}

void updateSum(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] += (sr - sl + 1) * val;
        if (sl != sr) {
            laz[ind*2] = {(laz[ind*2].first==2?2:1), laz[ind*2].second+val};
            laz[ind*2+1] = {(laz[ind*2+1].first==2?2:1), laz[ind*2+1].second+val};
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    updateSum(ind*2, sl, mid, ql, qr, val);
    updateSum(ind*2+1, mid+1, sr, ql, qr, val);
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
    ll n, q, o, v, ql, qr;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];

    build(1, 0, n);

    while (q --> 0) {
        cin >> o >> ql >> qr;
        if (o == 1)
            cin >> v, updateSum(1, 0, n, ql, qr, v);
        else if (o == 2)
            cin >> v, updateVal(1, 0, n, ql, qr, v);
        else
            cout << query(1, 0, n, ql, qr) << endl;
    }

    return 0;
}