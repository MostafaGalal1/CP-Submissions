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

bool compareBySize(const vector<ll>& vec1, const vector<ll>& vec2) {
    return vec1.size() > vec2.size();
}

int main() {
    ll t, tt;
    cin >> t;
    tt= t;

    while (t--) {
        ll n, k, p;
        cin >> n;
        map<ll, ll> mapp;

        vector<vector<ll>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> p;
                mapp[p]++;
                v[i].push_back(p);
            }
        }

        bool done;
        for (int i = 0; i < n; ++i) {
            done = false;
            for (long long j : v[i]) {
                if (mapp[j] < 2) {
                    done = true;
                    break;
                }
            }
            if (!done)
                break;
        }

        if (!done)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }


    return 0;
}