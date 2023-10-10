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
        ll n;
        cin >> n;
        vector<ll> a(n);

        ll ne = 0;
        ll ind = -1;
        ll mn = LONG_LONG_MAX;
        bool ze = false;

        ll res = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            res += abs(a[i]);

            if (a[i] == 0){
                ze = true;
            } else if (a[i] < 0) {
                ne++;
            }

            if (abs(a[i]) < mn){
                ind = i;
                mn = abs(a[i]);
            }
        }

        if (!ze && ne%2==1){
            res -= 2 * abs(a[ind]);
        }

        cout << res << endl;
    }
    return 0;
}