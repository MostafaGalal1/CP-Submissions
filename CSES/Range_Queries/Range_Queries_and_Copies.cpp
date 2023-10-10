#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll arr[N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

struct Vertex {
    Vertex *l, *r;
    ll val;
    Vertex(ll val) : l(nullptr), r(nullptr), val(val) {}
};

Vertex* build(ll sl, ll sr) {
    if (sl == sr)
        return new Vertex(arr[sl]);
    ll mid = sl + (sr - sl) / 2;
    auto* v = new Vertex(0);
    v->l = build(sl, mid);
    v->r = build(mid+1, sr);
    v->val += v->l->val + v->r->val;
    return v;
}

ll query(Vertex* v, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return 0;
    if (ql <= sl && qr >= sr)
        return v->val;
    ll mid = sl + (sr - sl) / 2;
    return query(v->l, sl, mid, ql, qr) + query(v->r, mid+1, sr, ql, qr);
}

Vertex* update(Vertex* v, ll ind, ll sl, ll sr, ll val) {
    if (sl == sr)
        return new Vertex(val);
    ll mid = sl + (sr - sl) / 2;
    auto* w = new Vertex(0);
    if (ind <= mid) {
        w->r = v->r;
        w->l = update(v->l, ind, sl, mid, val);
        w->val += w->l->val + w->r->val;
        return w;
    } else {
        w->l = v->l;
        w->r = update(v->r, ind, mid+1, sr, val);
        w->val += w->l->val + w->r->val;
        return w;
    }
}

int main() {
    fast();
    ll n, q, ql, qr, o, k, sz = 1;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
        cin >> arr[i];

    vector<Vertex*> roots;
    roots.push_back(new Vertex(0));
    roots.push_back(build(1, n));

    while (q --> 0) {
        cin >> o >> k;
        if (o == 1) {
            cin >> ql >> qr;
            roots[k] = update(roots[k], ql, 1, n, qr);
        } else if (o == 2) {
            cin >> ql >> qr;
            cout << query(roots[k], 1, n, ql, qr) << endl;
        } else {
            roots.push_back(roots[k]);
            sz++;
        }
    }

    return 0;
}