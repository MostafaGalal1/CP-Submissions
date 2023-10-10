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
        ll n;
        bool done = false;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        ll mx = 0;
        ll cnt = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        ll ind;
        bool start = false;
        for (int i = 0; i < n; ++i) {
            if (a[i].second == 0)
                ind = i, start = true;
            if (start){
                a[ind].first = (ll)ceil((a[i].first + a[ind].first)/2.0);
            }
        }

        cout << a[ind].first << endl;
    }
    return 0;
}