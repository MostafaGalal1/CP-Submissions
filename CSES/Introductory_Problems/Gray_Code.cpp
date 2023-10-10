#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return (1LL * a * b)%mod;
}

ll add(ll a , ll b){
    return a + b %mod;
}

ll fp( ll b , ll p){
    if (p < 0)
        return 0;
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp%mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(1<<n));
        for (int i = 0; i < n; ++i) {
            ll cnt = 1<<i;
            bool xo = false;
            for (int j = 0; j < 1<<n; ++j) {
                if (!xo)
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
                cnt++;
                cnt%=1<<(i+1);
                if (!cnt)
                    xo ^= true;
            }
        }

        for (int i = 0; i < 1<<n; ++i) {
            for (int j = n-1; j >= 0; --j) {
                cout << a[j][i];
            }
            cout << endl;
        }
    }

    return 0;
}