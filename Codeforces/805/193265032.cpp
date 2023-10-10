#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll l, r;
    cin >> l >> r;

    if (l == r)
        cout << l;
    else
        cout << 2;
    cout << endl;

    return 0;
}
