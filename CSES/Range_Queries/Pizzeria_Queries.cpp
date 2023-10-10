#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll arrp[N], arrs[N], pre[4*N], suf[4*N];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void buildpre (ll ind, ll sl, ll sr) {
    if (sl == sr){
        pre[ind] = arrp[sl];
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    buildpre(ind*2, sl, mid);
    buildpre(ind*2+1, mid+1, sr);
    pre[ind] = min(pre[ind*2], pre[ind*2+1]);
}

void updatepre(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        pre[ind] = val;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    updatepre(ind*2, sl, mid, ql, qr, val);
    updatepre(ind*2+1, mid+1, sr, ql, qr, val);
    pre[ind] = min(pre[ind*2], pre[ind*2+1]);
}

ll querypre(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return LONG_MAX;
    if (ql <= sl && qr >= sr)
        return pre[ind];
    ll mid = sl + (sr - sl) / 2;
    return min(querypre(ind*2, sl, mid, ql, qr), querypre(ind*2+1, mid+1, sr, ql, qr));
}

void buildsuf(ll ind, ll sl, ll sr) {
    if (sl == sr){
        suf[ind] = arrs[sl];
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    buildsuf(ind*2, sl, mid);
    buildsuf(ind*2+1, mid+1, sr);
    suf[ind] = min(suf[ind*2], suf[ind*2+1]);
}

void updatesuf(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        suf[ind] = val;
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    updatesuf(ind*2, sl, mid, ql, qr, val);
    updatesuf(ind*2+1, mid+1, sr, ql, qr, val);
    suf[ind] = min(suf[ind*2], suf[ind*2+1]);
}

ll querysuf(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return LONG_MAX;
    if (ql <= sl && qr >= sr)
        return suf[ind];
    ll mid = sl + (sr - sl) / 2;
    return min(querysuf(ind*2, sl, mid, ql, qr), querysuf(ind*2+1, mid+1, sr, ql, qr));
}

int main() {
    fast();
    ll n, q, op, ql, qr;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
        cin >> arrp[i], arrs[i] = arrp[i];

    for (int i = 1; i <= n; ++i) {
        arrp[i] += i;
        arrs[n+1-i] += i;
    }

    buildpre(1, 1, n);
    buildsuf(1, 1, n);

    while (q --> 0) {
        cin >> op >> ql;
        if (op == 1) {
            cin >> qr;
            updatepre(1, 1, n, ql, ql, qr+ql);
            updatesuf(1, 1, n, ql, ql, qr+n-ql+1);
        } else
            cout << min(querypre(1, 1, n, ql, n) - ql, querysuf(1, 1, n, 1, ql) - (n-ql+1)) << endl;
    }

    return 0;
}