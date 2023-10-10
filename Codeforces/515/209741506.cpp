#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef unsigned long long ll;

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
//    ll t;
//    cin >> t;
//
//    while (t--) {
        ll n;
        string s, r;
        cin >> n >> s;
        map<char, string> mapp;
        mapp['0'] = "";
        mapp['1'] = "";
        mapp['2'] = "2";
        mapp['3'] = "3";
        mapp['4'] = "322";
        mapp['5'] = "5";
        mapp['6'] = "53";
        mapp['7'] = "7";
        mapp['8'] = "7222";
        mapp['9'] = "7332";

        for (int i = 0; i < n; ++i) {
            if (s[i] != '0' && s[i] != '1')
                r += mapp[s[i]];
        }

        sort(r.rbegin(), r.rend());
        cout << r << endl;
//    }

    return 0;
}
