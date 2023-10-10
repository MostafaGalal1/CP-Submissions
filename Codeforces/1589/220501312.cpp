#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll a, b, n;
        cin >> a >> b;
        n = a * b;
        cout << n/3 - (n%3==1?1:0) + (n-(n/3 - (n%3==1?1:0))*3)/2 << endl;
    }

    return 0;
}