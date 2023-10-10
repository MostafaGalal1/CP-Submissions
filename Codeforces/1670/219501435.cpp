#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i)
                r.push_back(n / i);
        }
    }
    return r;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, k;
        char ch;
        cin >> n;
        string s;
        map<char, bool> mapp;
        cin >> s;

        cin >> k;
        for (int i = 0; i < k; ++i) {
            cin >> ch;
            mapp[ch] = true;
        }

        ll cnt = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (mapp[s[i]]){
                mx = max(mx, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }

        cout << mx << endl;
    }
    return 0;
}