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

int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, nu;
        bool done = false;
        cin >> n;
        multiset<ll> a;

        auto ind = a.begin();
        ll cn = 0;

        vector<ll> res;
        for (int i = 0; i < n; ++i) {
            cin >> nu;
            a.insert(nu);

            if (i == 0)
                ind = a.begin();

            auto it = ind;
            for (it = ind; it != a.end(); it++) {
                if (*it >= a.size()-cn){
                    res.push_back(a.size()-cn);
                    ind = it;
                    break;
                }
                cn++;
            }

            if (it == a.end())
                res.push_back(n);
        }

        for (int i = 0; i < n; ++i) {
            cout << res[i] << ' ';
        }

        cout << endl;
    }
    return 0;
}