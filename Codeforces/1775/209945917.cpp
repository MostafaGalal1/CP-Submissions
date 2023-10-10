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

bool compareBySize(const vector<ll>& vec1, const vector<ll>& vec2) {
    return vec1.size() > vec2.size();
}

int main() {
    ll t, tt;
    cin >> t;
    tt= t;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        map<ll, ll> mapp;

        string s = bitset<64>(n).to_string();
        reverse(s.begin(), s.end());

        bool one =  false;
        mapp[n] = n;
        for (int i = 0; i < 64; ++i) {
            if (s[i] == '1')
                one = true;
            else if (one){
                string r(i+1, '0'), g;
                r += s.substr(i+1, 64-i);
                g = r;
                g[i] = '1';
                reverse(r.begin(), r.end());
                reverse(g.begin(), g.end());
                bitset<64> rr(r), gg(g);
                mapp[rr.to_ullong()] = gg.to_ullong();
                one = false;
            }
        }

        if (mapp[x] || !x)
            cout << mapp[x];
        else
            cout << -1;
        cout << endl;
    }


    return 0;
}