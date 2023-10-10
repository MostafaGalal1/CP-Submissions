#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll a, b, c;
    cin >> a >> b >> c;

    long double h = sqrtl(c*b/a);
    long double l = c/h;
    long double w = b/h;

    cout << (ll)(4*l+4*w+4*h) << endl;

    return 0;
}