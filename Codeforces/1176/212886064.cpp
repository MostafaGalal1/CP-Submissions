#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n, nu;
        cin >> n;
        ll one = 0, two = 0, three = 0;

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            if (nu%3==2)
                two++;
            else if (nu%3==1)
                one++;
            else
                three++;
        }

        ll mn = min(one, two);
        ll res = three + mn;
        two -= mn, one -= mn;
        res += (one>=0?one/3:0) + (two>=0?two/3:0);
        cout << res << endl;
    }

    return 0;
}