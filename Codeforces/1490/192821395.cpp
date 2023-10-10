#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
vector<ll> v(10000);

int main()
{
    fast();

    for (ll i = 0; i < 10000; ++i) {
        v[i] = (i+1) * (i+1) * (i+1);
    }

    ll t;
    cin >> t;

    while (t-->0) {
        ll n;
        cin >> n;

        bool done = false;

        for (int i = 0; i < 10000; i++) {
            auto it = lower_bound(v.begin(), v.end(), n - v[i]);
            if (*it + v[i] == n){
                done = true;
                break;
            }
        }

        if (done)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}