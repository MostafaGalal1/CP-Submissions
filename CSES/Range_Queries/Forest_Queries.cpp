#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e3+2;
ll arr[N], seg[N][4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void build (ll i, ll ind, ll sl, ll sr) {
    if (sl == sr){
        seg[i][ind] = arr[sl];
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    build(i, ind*2, sl, mid);
    build(i, ind*2+1, mid+1, sr);
    seg[i][ind] = seg[i][ind*2] + seg[i][ind*2+1];
}

ll query(ll i, ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return 0;
    if (ql <= sl && qr >= sr)
        return seg[i][ind];
    ll mid = sl + (sr - sl) / 2;
    return query(i, ind*2, sl, mid, ql, qr) + query(i, ind*2+1, mid+1, sr, ql, qr);
}

int main() {
    fast();
    char ch;
    ll n, q, ql1, qr1, ql2, qr2;
    cin >> n >> q;

    for (int i = 0; i <= n; ++i)
        arr[i] = 0;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            cin >> ch;
            arr[j] += (ch == '*'?1:0);
        }
        build(i, 1, 0, n);
    }

    while (q --> 0) {
        cin >> ql1 >> qr1 >> ql2 >> qr2;
        cout << query(ql2, 1, 0, n, qr1, qr2) - query(ql1-1, 1, 0, n, qr1, qr2) << endl;
    }

    return 0;
}