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

void rec (string r, multiset<char> ms, set<string>& si){
    if (ms.empty()){
        si.insert(r);
        return;
    }
    for (char m : ms) {
        multiset<char> ns = ms;
        ns.erase(ns.find(m));
        rec(r + m, ns, si);
        ns.insert(m);
    }
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n;
        string s;
        cin >> s;
        n = (ll)s.length();
        set<string> si;
        multiset<char> ms;

        for (int i = 0; i < n; ++i)
            ms.insert(s[i]);
        rec("", ms, si);

        cout << (ll)si.size() << endl;
        for (auto& ss : si)
            cout << ss << endl;
    }

    return 0;
}