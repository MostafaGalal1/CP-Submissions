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
        ll n, k, l, r;
        cin >> n >> k;
        vector<pair<ll, ll>> a(51);

        for (int i = 0; i < 51; ++i) {
            a[i].first = 0;
            a[i].second = i;
        }

        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            if (!(l > k || r < k)){
                for (ll j = l; j <= r; ++j) {
                    a[j].first++;
                }
            }
        }

        sort(a.begin(), a.end());

        if (a[50].first == a[49].first || a[50].second != k){
            cout << "NO";
        } else
            cout << "YES";

        cout << endl;
    }

    return 0;
}