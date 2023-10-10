#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7, N = 1e5+10;
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

    while(t --> 0) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == (b>=c? b:2*c-b))
            cout << 3;
        else if (a < (b>=c? b:2*c-b))
            cout << 1;
        else
            cout << 2;
        
        
        cout << endl;
    }

    return 0;
}
