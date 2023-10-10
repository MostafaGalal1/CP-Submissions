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
        bool done = false;
        ll mul = 0;
        ll n;
        cin >> n;

        if (((n-1)*(2*n-1))%3 == 0)
            mul = (n%mod * n%mod)%mod + (n * (n-1) / 2)%mod + (((n-1)*(2*n-1)/3)%mod * n%mod)%mod;
        else if ((n*(2*n-1))%3 == 0)
            mul = (n%mod * n%mod)%mod + (n * (n-1) / 2)%mod + ((n*(2*n-1)/3)%mod * (n-1)%mod)%mod;
        else
            mul = (n%mod * n%mod)%mod + (n * (n-1) / 2)%mod + (((n-1)*(n)/3)%mod * (2*n-1)%mod)%mod;

        cout << (2022 * mul)%mod << endl;
    }
    return 0;
}