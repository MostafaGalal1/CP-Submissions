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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll,ll>> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i+1;
            b[i].first = a[i].first;
            b[i].second = a[i].second;
        }

        ll st = 0;
        sort(a.begin(), a.end());

        for (ll i = 0; i <= 1000; i++) {
            auto it = upper_bound(a.begin(), a.end(), make_pair(i, n));
            if (it != a.begin())
                it = prev(it);

            while ((*it).first == i){
                if ((*it).first <= m){
                    st++;
                    m -= (*it).first;
                    if (it != a.begin())
                        it = prev(it);
                    else
                        break;
                } else {
                    break;
                }
            }
        }

        if (st != 0 && st != n && m + a[st-1].first >= b[st].first)
            st++;

        cout << n + 1 - st << endl;
    }
    return 0;
}