#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x = max(x-a, 0ll);
        y = max(y-b, 0ll);
        cout << (c - x - y >= 0? "YES":"NO") << endl;
    }

    return 0;
}