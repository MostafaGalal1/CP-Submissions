#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll add(ll a, ll b){
    return (a + b)%mod;
}

ll sub(ll a, ll b){
    return ((a - b)%mod + mod)%mod;
}

ll mul(ll a, ll b){
    return (a * b)%mod;
}

ll fp (ll a, ll p){
    if (p == 0)
        return 1;
    ll tmp = fp(a, p/2);
    tmp = mul(tmp, tmp);
    if (p&1)
        tmp = mul(a, tmp);
    return tmp;
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        int n, k;
        cin >> n >> k;
        int tmp = k;
        int sum = 0;

        for (int i = 0; i < 32; ++i) {
            if (tmp & 1) {
                sum = add(sum, fp(n, i));
            }
            tmp = tmp >> 1;
        }

        cout << sum << endl;
    }

    return 0;
}