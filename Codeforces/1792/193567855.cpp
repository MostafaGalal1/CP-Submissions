#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;

        ll res = a1;

        if (a1) {
            ll tm = min(a2, a3);
            res += 2 * tm;
            a2 -= tm;
            a3 -= tm;

            if (a2 && !a3) {
                tm = min(a2, a1);
                res += tm;
                a1 -= tm;
                a2 -= tm;
            } else if (!a2 && a3) {
                tm = min(a3, a1);
                res += tm;
                a1 -= tm;
                a3 -= tm;
            }

            if (a1) {
                res += min(a1, a4);
                a4 -= min(a1, a4);
            }
        }

        if (a2 || a3 || a4)
            res++;

        cout << res << endl;
    }
    return 0;
}