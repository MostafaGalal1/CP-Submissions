#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0){
        ll n, k, a, b;
        cin >> k >> n >> a >> b;

        if (b * n < k){
            ll res = k - 1 - b * n;
            res = min(res / (a-b), n);
            cout << res;
        } else {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}