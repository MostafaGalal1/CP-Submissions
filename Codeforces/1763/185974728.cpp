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
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }

        sort(a.begin(), a.end());

        ll rest = k;
        bool done = false;
        while (rest > 0){
            auto it = lower_bound(a.begin(), a.end(), make_pair(k+1, 0ll));
            ll mn = LONG_LONG_MAX;
            if (it == a.end()){
                cout << "YES";
                done = true;
                break;
            }
            for (int i = it - a.begin(); i < n; ++i) {
                if (mn > a[i].second)
                    mn = a[i].second;
            }
            rest -= mn;
            k += rest;
        }

        if (!done)
            cout << "NO";
        cout << endl;
    }
    return 0;
}