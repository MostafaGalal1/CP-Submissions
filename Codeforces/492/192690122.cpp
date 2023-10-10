#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, r, k;
    cin >> n >> r >> k;
    multiset<pair<ll, ll>> s;
    ll cr = 0;

    for (int i = 0; i < n; ++i) {
        pair<ll, ll> a;
        cin >> a.second >> a.first;
        cr += a.second;
        s.insert(a);
    }

    ll cs = k * n - cr;
    ll cnt = 0;

    while (cs > 0 && !s.empty()){
        for (auto & ss : s) {
            cnt += min(r - ss.second, cs) * ss.first;
            cs -= min(r - ss.second, cs);

            if (cs <= 0){
                break;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}