#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;

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

ll mex(vector<ll> a){
    set<ll> s;
    ll n = (ll)a.size();

    for (int i = 0; i < n; ++i)
        s.insert(a[i]);

    ll cu = 0;
    for(auto ch : s){
        if (ch != cu)
            break;
        cu++;
    }

    return cu;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        vector<pair<ll, ll>> a(4);
        ll r, l;

        for (int i = 0; i < 4; ++i) {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        r = a[0].first, l = a[2].first;

        std::sort(a.begin(), a.end());

        if ((a[1].second == 3 && a[2].second == 2) || (a[1].second == 1 && a[2].second == 4) || (a[1].second == 3 && a[2].second == 4) || (a[1].second == 1 && a[2].second == 2) || (a[1].first == a[2].first))
            cout << a[1].first;
        else
            cout << r + l;
        cout << endl;
    }


    return 0;
}