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

ll N = 2e5 + 5, inf = LONG_MAX, mod = 998244353;
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

ll fibonacci(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    double fn = (pow(phi, n) - pow(psi, n)) / sqrt(5);
    return static_cast<ll>(round(fn));
}

bool red;
ll dfs(ll node, ll res, vector<vector<ll>>& adj, vector<bool>& vis, map<ll, bool>& mapp) {
    vis[node] = true;
    mapp[node] = true;

    if (!red && (mapp[node-1] || mapp[node+1]))
        red = true;
    for (auto ch : adj[node]) {
        if (!vis[ch])
            return dfs(ch, res+1, adj, vis, mapp);
    }
    return res;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, res = 0;
        bool done = false;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        vector<ll> b(n), c(n), o(n);
        set<ll> s;
        map<ll, ll> mapp, ch;

        for (int i = 0; i < n; ++i) {
            s.insert(i+1);
            cin >> a[i].first, a[i].second = i;
            ch[a[i].first]++;
            if (ch[a[i].first] > 2)
                done = true;
            o[i] = a[i].first;
        }

        sort(a.begin(), a.end());
        for (int i = 0; i < n && !done; ++i) {
            auto it = s.upper_bound(a[i].first);
            if (it == s.begin()) {
                done = true;
                break;
            } else
                it--;
            if (*it == a[i].first){
                b[a[i].second] = a[i].first;
                c[a[i].second] = a[i].first;
                mapp[a[i].first] = a[i].second;
                s.erase(it);
            } else {
                b[a[i].second] = *it;
                c[mapp[a[i].first]] = *it;
                c[a[i].second] = a[i].first;
                s.erase(it);
            }
        }

        for (int i = 0; i < n && !done; ++i) {
            if (max(b[i], c[i]) == o[i])
                res++;
        }

        if (res == n && !done) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i)
                cout << b[i] << " ";
            cout << endl;
            for (int i = 0; i < n; ++i)
                cout << c[i] << " ";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}