#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 5e5+5;
ll seg[4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] = val;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = seg[ind*2] ^ seg[ind*2+1];
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return 0;
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return query(ind*2, sl, mid, ql, qr) ^ query(ind*2+1, mid+1, sr, ql, qr);
}

int main() {
    fast();
    ll n, q, ql, qr;
    cin >> n >> q;

    unordered_map<ll, ll> p;
    vector<ll> a(n+1), pre(n+1);
    vector<pair<ll, ll>> s[N];

    pre[0] = 0;
    for (ll i = 1; i <= n; ++i)
        cin >> a[i], pre[i] = pre[i-1] ^ a[i];

    vector<ll> res(q);
    for (int i = 0; i < q; ++i) {
        cin >> ql >> qr;
        s[qr].emplace_back(ql, i);
    }

    for (int i = 1; i <= n; ++i) {
        update(1, 0, n, i, i, a[i]);
        if (p[a[i]])
            update(1, 0, n, p[a[i]], p[a[i]], 0);
        for (auto& it : s[i])
                res[it.second] = pre[i] ^ pre[it.first - 1] ^ query(1, 0, n, it.first, i);
        p[a[i]] = i;
    }

    for (ll r : res)
        cout << r << '\n';;
    return 0;
}