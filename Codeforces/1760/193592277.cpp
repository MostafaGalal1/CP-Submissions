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

    while (t --> 0){
        ll n, res = 0;
        cin >> n;
        vector<ll> a(n), o(n, 0), z(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] && i < n-1)
                o[i+1]++;
            if (i)
                o[i] += o[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            if (!a[i] && i > 0) {
                z[i-1]++;
                res += o[i];
            }
            if (i < n-1)
                z[i] += z[i + 1];
        }

        ll mx = res;
        for (int i = 0; i < n/2; ++i) {
            if (!a[i] && a[n - 1 - i]){
                if (o[n-1-i] - z[n-1-i] >= z[i] - o[i])
                    mx = max(mx, res + o[n-1-i] - z[n-1-i]);
                else
                    mx = max(mx, res + z[i] - o[i]);
            } else if (!a[i]){
                mx = max(mx, res + z[i] - o[i]);
            } else if (a[n-1-i]){
                mx = max(mx, res + o[n-1-i] - z[n-1-i]);
            }
        }

        cout << mx << endl;
    }

    return 0;
}