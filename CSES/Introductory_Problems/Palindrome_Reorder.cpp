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
        ll n, o = 0;
        string s, c;
        cin >> s;
        n = (ll)s.length();
        unordered_map<char, ll> mapp;

        for (int i = 0; i < n; ++i)
            mapp[s[i]]++;
        for (auto m : mapp) {
            if (m.second%2)
                c += m.first, o++;
        }

        string r, rr;
        if (n%2 && o == 1){
            mapp[c[0]]--;
            for (auto& m : mapp) {
                while (m.second) {
                    r += m.first;
                    mapp[m.first] -= 2;
                }
            }
        } else if (n%2 == 0 && !o){
            for (auto& m : mapp) {
                while (m.second) {
                    r += m.first;
                    mapp[m.first] -= 2;
                }
            }
        } else {
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        rr = r;
        reverse(rr.begin(), rr.end());
        cout << r << (o==1?c:"") << rr << endl;
    }

    return 0;
}