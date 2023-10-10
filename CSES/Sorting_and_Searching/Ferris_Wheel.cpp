#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, k, nu;
        cin >> n >> k;
        multiset<ll> a;

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            a.insert(nu);
        }

        ll res = 0;
        while (!a.empty()){
            ll sum = *prev(a.end());
            ll cnt = 1;
            a.erase(prev(a.end()));
            auto it = a.lower_bound(k-sum);
            while (cnt < 2){
                if (*it == k-sum) {
                    a.erase(it);
                    break;
                } else if (it != a.begin()){
                    sum += *prev(it);
                    cnt++;
                    a.erase(prev(it));
                    it = a.lower_bound(k - sum);
                } else {
                    break;
                }
            }
            res++;
        }

        cout << res << endl;
    }

    return 0;
}