#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), res(n, 0), p(n), h(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        p[0] = b[0];
        for (int i = 1; i < n; ++i) {
            p[i] = b[i];
            p[i] += p[i-1];
        }

        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(p.begin(), p.end(), a[i] + (i > 0? p[i - 1] : 0));
            if (it != p.end()){
                if (*it > a[i]) {
                    if (it != p.begin()) {
                        res[it - p.begin()] += a[i] + (i > 0 ? p[i - 1] : 0) - *prev(it);
                    } else {
                        res[it - p.begin()] += a[i] + (i > 0 ? p[i - 1] : 0);
                    }
                    h[it - p.begin()]++;
                } else {
                    if ((it - p.begin() + 1) < n)
                        h[it - p.begin() + 1]++;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            h[i] += h[i-1];
        }

        for (int i = 0; i < n; ++i) {
            cout << b[i] * (i + 1 - h[i]) + res[i] << ' ';
        }

        cout << endl;
    }

    return 0;
}