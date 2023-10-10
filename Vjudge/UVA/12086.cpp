#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll cnt = 0, arr[N], seg[4*N];

void build(ll ind, ll low, ll high){
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    ll mid = (high + low) / 2;
    build(ind * 2 + 1, low, mid);
    build(ind * 2 + 2, mid + 1, high);
    seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
}

ll query(ll ind, ll low, ll high, ll l, ll r){

    if (low >= l && r >= high)
        return seg[ind];

    ll mid = (high + low) / 2;
    ll res = 0ll;
    if (mid >= l)
        res += query(ind*2+1, low, mid, l ,r);
    if (mid < r)
        res += query(ind*2+2, mid+1, high, l, r);
    return res;
}

void update(ll ind, ll low, ll high, ll l, ll r){
    if (low == high && low == l) {
        seg[ind] = r;
        return;
    }

    ll mid = (high + low) / 2;
    if (low <= l && l <= mid)
        update(ind*2+1, low, mid, l, r);
    else
        update(ind*2+2, mid+1, high, l, r);
    seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
}

int main() {
    string s;
    ll n, l, r;
    cin >> n;

    while (n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        memset(seg, 0, sizeof(seg));

        cnt++;
        for (ll i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        build(0, 0, n - 1);

        cout << "Case " << cnt << ":\n";
        cin >> s;
        while (s != "END") {
            cin >> l >> r;
            if (s == "S") {
                update(0, 0, n - 1, l - 1, r);
            }
            if (s == "M")
                cout << query(0, 0, n - 1, l - 1, r - 1) << '\n';
            cin >> s;
        }
        cin >> n;
        if (n)
            cout << '\n';
    }
    return 0;
}