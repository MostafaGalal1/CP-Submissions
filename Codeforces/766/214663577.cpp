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

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll n, cnt = 1;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    bool done = false;
    for (int i = 0; i < n-2; ++i) {
        if (a[i] + a[i+1] > a[i+2])
            done = true;
    }

    if (done)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}