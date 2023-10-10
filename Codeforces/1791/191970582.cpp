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
        ll n, c;
        cin >> n >> c;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            a[i].second = i+1;
            cin >> a[i].first;
            a[i].first += i+1;
        }

        sort(a.begin(), a.end());
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            if (c >= a[i].first){
                res++;
                c -= a[i].first;
            } else {
                break;
            }
        }

        cout << res << endl;
    }
    return 0;
}