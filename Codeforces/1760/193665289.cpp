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

    while (t-->0) {
        ll n, c, d;
        cin >> n >> c >> d;
        vector<ll> a(n), p(n+1);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        p[0] = 0;
        for (int i = 1; i < n+1; ++i) {
            p[i] = a[i-1];
            p[i] += p[i-1];
        }

        ll co = 0;
        for (int i = n-1; i >= max(n-d, 0ll); --i)
            co += a[i];

        if (co >= c)
            cout << "Infinity";
        else if (a[n-1] * d < c)
            cout << "Impossible";
        else {
            ll cn = 1, k;

            while (true){
                ll su = 0;
                for (int i = 0; i < d/cn; ++i)
                    su += p[n] - p[max(n-cn, 0ll)];

                su += p[n] - p[max(n-d%cn, 0ll)];
                if (su >= c)
                    k = cn - 1;
                if (cn == d)
                    break;
                cn++;
            }

            cout << k;
        }
        cout << endl;
    }
    return 0;
}