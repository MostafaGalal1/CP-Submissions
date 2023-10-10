#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(x), p;

        for (int i = 0; i < x; ++i) {
          cin >> a[i];
        }
        std::sort(a.begin(), a.end());

        p.push_back(a[0] + (n - a[x-1]) - 1);
        for (int i = 1; i < x; ++i) {
            p.push_back(abs(a[i] - a[i-1]) - 1);
        }

        sort(p.begin(), p.end());
        ll sub = 0, cnt = 0;

        for (int i = 0; i < x; ++i) {
            if (p[x-1-i]-sub == 1)
                cnt++;
            cnt += max(p[x-1-i]-1-sub, 0ll);
            sub += 4;
        }

        cout << n - cnt << endl;
    }

    return 0;
}