#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+5;
ll arr[N],laz[4*N];
string s;
pair<ll,ll> seg[4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void build (ll ind, ll sl, ll sr) {
    if (sl == sr){
        if (s[sl] == '0')
            seg[ind].first = arr[sl], seg[ind].second = 0;
        else if (s[sl] == '1')
            seg[ind].second = arr[sl], seg[ind].first = 0;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    build(ind*2, sl, mid);
    build(ind*2+1, mid+1, sr);
    seg[ind].first = seg[ind*2].first ^ seg[ind*2+1].first;
    seg[ind].second = seg[ind*2].second ^ seg[ind*2+1].second;
}

void lazy (ll ind, ll sl, ll sr) {
    if (laz[ind] != 0) {
        seg[ind].first ^= laz[ind];
        seg[ind].second ^= laz[ind];
        if (sl != sr) {
            laz[ind*2] ^= seg[ind*2].first ^ seg[ind*2].second;
            laz[ind*2+1] ^= seg[ind*2+1].first ^ seg[ind*2+1].second;
        }
        laz[ind] = 0;
    }
}

void update(ll ind, ll sl, ll sr, ll ql, ll qr) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        ll xo = seg[ind].first ^ seg[ind].second;
        seg[ind].first ^= xo;
        seg[ind].second ^= xo;
        if (sl != sr) {
            laz[ind*2] ^= seg[ind*2].first ^ seg[ind*2].second;
            laz[ind*2+1] ^= seg[ind*2+1].first ^ seg[ind*2+1].second;
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr);
    update(ind*2+1, mid+1, sr, ql, qr);
    seg[ind].first = seg[ind*2].first ^ seg[ind*2+1].first;
    seg[ind].second = seg[ind*2].second ^ seg[ind*2+1].second;
}

pair<ll, ll> query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    lazy(ind, sl, sr);
    if (qr < sl || ql > sr)
        return {0, 0};
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    pair<ll, ll> p1 = query(ind*2, sl, mid, ql, qr), p2 = query(ind*2+1, mid+1, sr, ql, qr), r;
    r.first = p1.first ^ p2.first, r.second = p1.second ^ p2.second;
    return r;
}

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, q, ql, qr, op;
        cin >> n;
        for (ll i = 1; i <= n; ++i)
            cin >> arr[i];
        s.clear();
        cin >> s;
        s = 'b' + s;

        build(1, 1, n);

        cin >> q;
        while (q-- > 0) {
            cin >> op >> ql;
            if (op == 1)
                cin >> qr, update(1, 1, n, ql, qr);
            else
                cout << (ql == 0 ? query(1, 1, n, 1, n).first : query(1, 1, n, 1, n).second) << ' ';
        }
        cout << endl;
        for (int i = 0; i <= n; ++i)
            arr[i] = 0;
        for (ll i = 0; i <= 4*n; ++i)
            seg[i].first = 0, seg[i].second = 0, laz[i] = 0;
    }

    return 0;
}