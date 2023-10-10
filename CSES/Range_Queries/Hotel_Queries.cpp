#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll arr[N], seg[4*N];

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

//void lazy (ll ind, ll sl, ll sr) {
//    if (laz[ind] != 0) {
//        seg[ind] += (sr - sl + 1) * laz[ind];
//        if (sl != sr) {
//            laz[ind * 2] += laz[ind];
//            laz[ind*2+1] += laz[ind];
//        }
//        laz[ind] = 0;
//    }
//}

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
//    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] -= val;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = max(seg[ind*2], seg[ind*2+1]);
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr, ll k) {
//    lazy(ind, sl, sr);
    if (qr < sl || ql > sr || seg[ind] < k)
        return LONG_LONG_MAX;
    if (sl == sr)
        return sl;
    ll mid = sl + (sr - sl) / 2;
    if (seg[ind*2] >= k)
        return query(ind*2, sl, mid, ql, qr, k);
    else
        return query(ind*2+1, mid+1, sr, ql, qr, k);
}

int main() {
    fast();
    ll n, q, k;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 0, n);

    while (q --> 0) {
        cin >> k;
        ll res = query(1, 0, n, 1, n, k);
        res = res==LONG_LONG_MAX?0:res;
        if (res)
            update(1, 0, n, res, res, k);
        cout << res << endl;
    }

    return 0;
}