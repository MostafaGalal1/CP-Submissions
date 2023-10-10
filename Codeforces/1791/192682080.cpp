#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;

    while (t-->0) {
        ll n, q, op, l, r;
        cin >> n >> q;

        set<ll> s;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(i);
        }

        for (int i = 0; i < q; ++i) {
            cin >> op;
            if (op == 1){
                cin >> l >> r;
                l--, r--;

                while (!s.empty()) {
                    auto it = s.lower_bound(l);

                    if(it == s.end() || *it > r)
                        break;

                    ll k = *it;
                    ll tm = 0;
                    ll nu = a[k];

                    while (nu) {
                        tm += nu % 10;
                        nu /= 10;
                    }
                    
                    a[k] = tm;
                    s.erase(it);
                    if(a[k] > 9)
                        s.insert(k);

                    l = k+1;
                }
            } else {
                cin >> l;
                cout << a[l-1] << endl;
            }
        }
    }

    return 0;
}