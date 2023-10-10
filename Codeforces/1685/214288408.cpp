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
        ll n, nu;
        cin >> n;
        bool done = n%2;
        map<ll, ll> m;
        vector<ll> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> nu;
            v[i] = nu;
            m[nu]++;
            if (m[nu] > n/2)
                done = true;
        }

        if (done)
            cout << "NO";
        else {
            vector<ll> res;
            sort(v.begin(), v.end());
            for (int i = 0; i < n/2; ++i)
                res.push_back(v[i]), res.push_back(v[i+(n+1)/2]);
            for (int i = 0; i < n; ++i) {
                if ((res[(n + i - 1) % n] <= res[i] && res[i] <= res[(i + 1) % n]) ||
                    (res[(n + i - 1) % n] >= res[i] && res[i] >= res[(i + 1) % n]))
                    done = true;
            }
            if (done)
                cout << "NO";
            else {
                cout << "YES" << endl;
                for (auto r : res)
                    cout << r << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}