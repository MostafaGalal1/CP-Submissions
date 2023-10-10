#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        string s, r;
        bool done = false;
        getline(cin, s);
        getline(cin, r);
        map<char, ll> mapp;

        ll n = (ll)s.length(), m = (ll)r.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ')
                mapp[s[i]]++;
        }

        for (int i = 0; i < m; ++i) {
            if (r[i] != ' ' && !mapp[r[i]]){
                done = true;
                break;
            } else
                mapp[r[i]]--;
        }

        if (done)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}