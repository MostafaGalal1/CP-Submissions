#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
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
        bool done = false;
        multiset<ll> a;
        vector<ll> b;

        ll num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            a.insert(num);
        }

        for (int i = 0; i < m; ++i) {
            a.erase(a.begin());
            cin >> num;
            a.insert(num);
        }

        ll sum = 0;
        for (auto &i:a) {
            sum += i;
        }

        cout << sum << endl;
    }
    return 0;
}