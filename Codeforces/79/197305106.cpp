#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return 1LL * a * b %mod;
}

ll add( ll a , ll b){
    return (a + b) %mod;
}

ll fp( ll b , ll p){
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp %mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 1; i <= n; ++i)
        res = mul(res, i);
    return res;
}

ll inv(ll i){
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

ll func (ll n, ll k, vector<ll> & a){
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += min(a[j], k);
    }
    return sum;
}

enum crops {
    Grapes,
    Carrots,
    Kiwis
};

int main() {
    fast();

    ll n, m, k, q, x, y;
    cin >> n >> m >> k >> q;
    vector<ll> a;

    a.push_back(-1);
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        x--, y--;
        a.push_back(x * m + y);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        x--, y--;
        auto it = upper_bound(a.begin(), a.end(), x*m+y);
        if (*prev(it) == x*m+y)
            cout << "Waste" << endl;
        else {
            ll val = (((x * m + y) % 3 - ((prev(it) - a.begin()) % 3) + 3) % 3);
            if (val == 0)
                cout << "Carrots";
            else if (val == 1)
                cout << "Kiwis";
            else
                cout << "Grapes";
            cout << endl;
        }
    }
    return 0;
}