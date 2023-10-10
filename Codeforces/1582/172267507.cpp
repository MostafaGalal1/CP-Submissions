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

    while (t --> 0) {
        ll a, b, c;
        cin >> a >> b >> c;

        cout << ((a+b*2+c*3)%2? 1:0) << endl;
    }

    return 0;
}