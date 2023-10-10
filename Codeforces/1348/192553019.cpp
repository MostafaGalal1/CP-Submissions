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

    while (t --> 0){
        ll n, k;
        cin >> n >> k;
        bool done = false;
        ll num;

        set<ll> q;
        vector<ll> v;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            q.insert(num);
            v.push_back(num);
            if (q.size() > k)
                done = true;
        }

        if (!done) {
            cout << 100 * q.size() + 100 * max(k - (ll)q.size(), 0ll) << endl;
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < k - q.size(); ++j) {
                    cout << *q.begin() << ' ';
                }
                for (ll qq : q) {
                    cout << qq << ' ';
                }
            }
            cout << endl;
        } else
            cout << -1 << endl;
    }
    return 0;
}