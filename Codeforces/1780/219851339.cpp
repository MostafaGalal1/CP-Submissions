#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n;
        cin >> n;

        vector<ll> a(n), o, e;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i]%2)
                o.push_back(i);
            else
                e.push_back(i);
        }

        ll om = (ll)o.size(), em = (ll)e.size();
        if (om >= 3){
            cout << "YES" << endl;
            for (int i = 0; i < 3; ++i)
                cout << o[i]+1 << ' ';
        } else if (em >= 2 && om >= 1) {
            cout << "YES" << endl;
            for (int i = 0; i < 2; ++i)
                cout << e[i]+1 << ' ';
            cout << o[0]+1;
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}