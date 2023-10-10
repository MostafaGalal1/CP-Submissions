#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename  T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
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
    temp = mul(temp,temp)%mod;
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

vector<bool> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

ll divis(ll n) {
    ll r = 1;
    for (ll i = 1; i <= n/2; ++i) {
        if (n%r)
            return r;
        r++;
    }
    return r;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        string s, r;
        ll n, m;
        cin >> s >> n;
        s = '0' + s;
        m = (ll)s.length();

        ll cur = 0, ind = 0;
        for (int i = 1; i < m; ++i) {
            if (cur + (s[i] - '0') < n || (cur + (s[i] - '0') == n && s[i] != '0'))
                cur += s[i] - '0', ind = i;
            else
                break;
        }

        bool p = false;
        char ch;
        for (int i = ind+1; i < m-1; ++i)
            ch = '9' - s[i] + '0', r += ch, s[i] != '0'?p=true:0;
        if (ind != m-1)
            ch = '9' - s[m-1] + '1', r += ch, s[m-1] != '0'?p=true:0;

        for (int i = (ll)r.length()-1; i > 0; --i) {
            if (r[i] == ':')
                r[i] = '0', r[i-1]++;
        }
        if (r[0] == ':')
            r[0] = '0', r = '1' + r;

        cout << stoll((r.empty() || (cur == n && !p)?"0":(n==cur?to_string('9'-s[ind])+r:r)), nullptr, 10) << endl;
    }

    return 0;
}