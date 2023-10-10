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

ll dfs(ll node, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& val, vector<ll>& res) {
    vis[node] = true;
    ll xo = val[node];
    for (auto ch : adj[node]) {
        if (!vis[ch])
            xo ^= dfs(ch, adj, vis, val, res);
    }
    return res[node] = xo;
}

bool compareSecondElement(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.second < p2.second;
}

std::pair<ld, ld> solveQuadraticEquation(ld a, ld b, ld c) {
    ld discriminant = b * b - 4 * a * c;
    ld sqrtDiscriminant = std::sqrt(std::abs(discriminant));

    if (discriminant > 0) {
        ld root1 = (-b + sqrtDiscriminant) / (2 * a);
        ld root2 = (-b - sqrtDiscriminant) / (2 * a);
        return std::make_pair(root1, root2);
    } else if (discriminant == 0) {
        ld root = -b / (2 * a);
        return std::make_pair(root, root);
    } else {
        // No real roots, return a pair of NaN (Not a Number) values
        return std::make_pair(std::numeric_limits<ld>::quiet_NaN(), std::numeric_limits<ld>::quiet_NaN());
    }
}


int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll cnt = 1;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] == a[i+1])
                cnt++;
        }

        if (cnt == n)
            cout << -1;
        else {
            ll ind = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == a[n-1]) {
                    ind = i;
                    break;
                }
            }

            cout << ind << ' ' << n-ind << endl;
            for (int i = 0; i < ind; ++i) {
                cout << a[i] << ' ';
            }
            cout << endl;
            for (int i = ind; i < n; ++i) {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}