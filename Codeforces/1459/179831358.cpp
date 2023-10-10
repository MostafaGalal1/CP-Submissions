#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

        ll n;
        cin >> n;

    ll m = n / 2 + 1;
    if (n % 2 == 0) {
        cout << m * m;
    } else {
        cout << m * m + (m + 1) * (m + 1) - 1;
    }

    return 0;
}