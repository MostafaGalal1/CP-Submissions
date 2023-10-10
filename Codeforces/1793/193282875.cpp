#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll a, b, n, m;
        cin >> a >> b >> n >> m;

        ll x = n / (m+1);
        ll pr = min(a * m, b * (m+1)) * x;
        n %= (m+1);
        pr += n*min(a, b);
        cout << pr << endl;
    }

    return 0;
}
