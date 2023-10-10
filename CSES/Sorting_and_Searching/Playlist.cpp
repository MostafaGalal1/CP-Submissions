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
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, nu, mx = 0;
        cin >> n;
        map<ll, ll> mapp;
        queue<ll> q;

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            if (!mapp[nu]){
                q.push(nu);
                mapp[nu] = true;
                mx = max(mx, (ll)q.size());
            } else {
                while (q.front() != nu)
                    mapp[q.front()] = false, q.pop();
                q.pop();
                q.push(nu);
            }
        }

        cout << mx << endl;
    }

    return 0;
}