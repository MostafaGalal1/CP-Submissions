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

        ll n, nu;
        bool done = false;
        cin >> n;
        set<ll> a;
        vector<ll> res(n+1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            a.insert(nu);
            if (a.size() > 1 && nu == *prev(prev(a.end()))){
                res[*prev(a.end())]++;
            } else if (a.size() == 1 || nu == *prev(a.end())){
                res[nu]--;
            }
        }

        ll mx = -2, ind = 0;
        for (int i = 1; i < n+1; ++i) {
            if (mx < res[i]){
                mx = res[i];
                ind = i;
            }
        }

        cout << ind << endl;

    return 0;
}