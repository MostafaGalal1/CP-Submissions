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
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        y1 = max(y1 - x2, 0ll);
        z2 = max(z2 - x1, 0ll);
        cout << min(z1, y2) * 2 - min(y1, z2) * 2 << endl;
    }

    cout << endl;

    return 0;
}