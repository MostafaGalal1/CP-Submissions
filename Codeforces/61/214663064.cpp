#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


using namespace std;
typedef long long ll;
const ll N = 1e6;
ll arr[N], seg[4*N], laz[4*N];

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

void update(ll ind, ll sl, ll sr, ll ql, ll qr, ll val) {
    if (qr < sl || ql > sr)
        return;
    if (ql <= sl && qr >= sr) {
        seg[ind] += (sr - sl + 1) * val;
        if (sl != sr) {
            laz[ind*2] += val;
            laz[ind*2+1] += val;
        }
        return;
    }
    ll mid = sl + (sr - sl) / 2;
    update(ind*2, sl, mid, ql, qr, val);
    update(ind*2+1, mid+1, sr, ql, qr, val);
    seg[ind] = seg[ind*2] + seg[ind*2+1];
}

ll query(ll ind, ll sl, ll sr, ll ql, ll qr) {
    if (qr < sl || ql > sr)
        return 0;
    if (ql <= sl && qr >= sr)
        return seg[ind];
    ll mid = sl + (sr - sl) / 2;
    return query(ind*2, sl, mid, ql, qr) + query(ind*2+1, mid+1, sr, ql, qr);
}

ll nCr(ll n, ll r) {
    if (r > n - r)
        r = n - r;
    ll ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main() {
    fast();
    ll n, cnt = 1;
    cin >> n;

    ordered_set<ll> s;
    map<ll, ll> mapp;
    vector<ll> a(n+1);

    for (ll i = 1; i <= n; ++i)
        arr[i] = 0, cin >> a[i], s.insert(a[i]);
    build(1, 0, n);

    for (ll m : s)
        mapp[m] = cnt++;

    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        ll more = query(1, 0, n, 1, cnt - mapp[a[i]]), less = s.order_of_key(a[i]) - query(1, 0, n, cnt - mapp[a[i]], n);
        res += more * less;
        update(1, 0, n, cnt - mapp[a[i]], cnt - mapp[a[i]], 1);
    }
    cout << res << endl;

    return 0;
}