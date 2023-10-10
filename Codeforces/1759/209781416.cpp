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
    string s = "Yes";
    for (int i = 0; i < 6; ++i) {
        s += s;
    }
    
    while (t--) {
        string r;
        cin >> r;
        
        if (s.find(r) != string::npos){
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}
