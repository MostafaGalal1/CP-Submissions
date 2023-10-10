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

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul(ll a, ll b){
    return 1LL * a * b % mod;
}

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll fp(ll b, ll p){
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

vector<ll> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    vector<ll> v;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            if (i * i <= n) {
                v.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                    isPrime[j] = false;
            } else
                v.push_back(i);
        }
    }
    return v;
}

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
            if (i != n / i)
                r.push_back(n / i);
        }
    }
    return r;
}

void primeFactors(ll n, map<ll, ll>& m) {
    while (n % 2 == 0) {
        m[2]++;
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 2)
        m[n]++;
}

vector<vector<ll>> dentity(ll n){
    vector<vector<ll>> v(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        v[i][i] = 1;
    return v;
}

vector<vector<ll>> multiplication(vector<vector<ll>>& a, vector<vector<ll>>& b){
    ll n = (ll)a.size(), m = (ll)b[0].size();
    vector<vector<ll>> c(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < (ll)b.size(); ++k)
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    return c;
}

vector<vector<ll>> exponentiation(vector<vector<ll>>& a, ll p){
    if (p == 0)
        return dentity((ll)a.size());
    vector<vector<ll>> temp = exponentiation(a, p/2);
    temp = multiplication(temp, temp);
    if (p&1)
        temp = multiplication(temp, a);
    return temp;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n;
        cin >> n;

        if (n == 0)
            cout << 0;
        else if (n == 1)
            cout << 1;
        else {
            vector<vector<ll>> a = {{1, 1}, {1, 0}}, b = exponentiation(a, n - 1);
            cout << b[0][0];
        }
        cout << endl;
    }
    return 0;
}