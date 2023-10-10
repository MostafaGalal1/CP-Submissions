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

    while (t-->0){
        ll n;
        cin >> n;
        vector<ll> res(n);
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n-1; ++i) {
            res[a[i].second] = a[i].first - a[n-1].first;
        }
        res[a[n-1].second] = a[n-1].first - a[n-2].first;

        for (int i = 0; i < n; ++i) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}