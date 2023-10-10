#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        cout << -(n-1) << ' ' << n << endl;
    }

    return 0;
}