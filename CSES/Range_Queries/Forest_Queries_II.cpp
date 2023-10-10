#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e3+5, M = 1e3+5;
ll a[N][M], t[4*N][4*M];

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

void build_y(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        ll my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(ll vx, ll lx, ll rx) {
    if (lx != rx) {
        ll mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, M-1);
}

ll query_y(ll vx, ll vy, ll tly, ll try_, ll ly, ll ry) {
    if (ly > ry)
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    ll tmy = (tly + try_) / 2;
    return query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
           + query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

ll query_x(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return query_y(vx, 1, 0, M-1, ly, ry);
    ll tmx = (tlx + trx) / 2;
    return query_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
           + query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}

void update_y(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, ll x, ll y, ll new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        ll my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(ll vx, ll lx, ll rx, ll x, ll y, ll new_val) {
    if (lx != rx) {
        ll mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, M-1, x, y, new_val);
}

int main() {
    fast();
    char ch;
    ll n, q, op, qlx, qrx, qly, qry;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ch;
            if (ch == '*')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    build_x(1, 0, n-1);

    while (q --> 0) {
        cin >> op;
        if (op == 1){
            cin >> qlx >> qrx;
            qlx--, qrx--;
            if (a[qlx][qrx] == 0)
                a[qlx][qrx] = 1;
            else
                a[qlx][qrx] = 0;
            update_x(1, 0, n-1, qlx, qrx, (a[qlx][qrx]?1:0));
        } else {
            cin >> qlx >> qly >> qrx >> qry;
            qly--, qry--, qlx--, qrx--;
            cout << query_x(1, 0, n-1, qlx, qrx, qly, qry) << endl;
        }
    }

    return 0;
}