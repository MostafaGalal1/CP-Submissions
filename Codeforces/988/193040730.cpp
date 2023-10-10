#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n;
    cin >> n;
    vector<ll> a(n), res, r;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll mx = -1;
    for (int i = 0; i < n; ++i) {
        ll cnt = 0;
        res.push_back(a[i]);
        for (int j = 0; j < 31; ++j) {
            auto it = lower_bound(a.begin(), a.end(), a[i] + (ll)pow(2, j));

            if (it != a.end() && *it - a[i] == (ll)pow(2, j) && *it != a[i]) {
                res.push_back(*it);
                cnt = 1;

                auto itt = lower_bound(a.begin(), a.end(), a[i] + (ll)pow(2, j+1));
                if (itt != a.end() && *itt - a[i] == (ll)pow(2, j+1) && *itt != a[i]) {
                    res.push_back(*itt);
                    cnt = 2;
                    break;
                }
            }

            if (mx < cnt){
                mx = cnt;
                r = res;
            }

            res.clear();
            res.push_back(a[i]);
        }

        if (mx < cnt){
            mx = cnt;
            r = res;
        }

        if (mx == 2)
            break;

        res.clear();
    }

    cout << mx+1 << endl;
    for (int i = 0; i < (ll)r.size(); ++i) {
        cout << r[i] << ' ';
    }
    cout << endl;
    return 0;
}