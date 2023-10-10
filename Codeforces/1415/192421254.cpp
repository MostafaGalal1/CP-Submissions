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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll, ll> mapp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mapp[a[i]] = 0;
        }

        ll mn = LONG_LONG_MAX;
        for (auto & m : mapp) {
            for (ll i = 0; i < n; ++i) {
                if (a[i] != m.first){
                    m.second++;
                    i += k - 1;
                }
            }
            mn = min(mn, m.second);
        }

        cout << mn << endl;
    }
    return 0;
}