#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

        ll n, m;
        bool z = false;
        cin >> n >> m;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (!a[i])
                z = true;
        }

        ll res = 0;
        ll i;

        for (i = 0; i < m; ++i) {
            if (a[i] <= 0)
                a[i] = -a[i];
            else
                break;
        }

        if (!z && i < m){
            if (i){
                if ((m-i)%2){
                    if (a[i-1] <= a[i])
                        a[i-1] = -a[i-1];
                    else
                        a[i] = -a[i];
                }
            } else {
                if ((m-i)%2)
                    a[i] = -a[i];
            }
        }

        for (i = 0; i < n; ++i)
            res += a[i];

        cout << res << endl;

    return 0;
}