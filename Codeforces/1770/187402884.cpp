#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, k;
        cin >> n >> k;

        for (int i = 0; i < n/2; ++i) {
            cout << n-i << ' ' << i+1 << ' ';
        }
        if (n%2)
            cout << n/2+1;
        cout << endl;
    }
    return 0;
}