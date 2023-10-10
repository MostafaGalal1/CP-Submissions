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

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll dfs(ll x, ll y, ll n, ll m, vector<vector<char>>& a, vector<vector<bool>>& vis){
    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')
        return 0;
    ll cnt = 0;
    vis[x][y] = true;
    for (int i = 0; i < 1; ++i) {
        if (!vis[x + dx[i]][y + dy[i]])
            cnt += dfs(x + dx[i], y + dy[i], n, m, a, vis);
    }
    return cnt+1;
}

ll fibonacci(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    double fn = (pow(phi, n) - pow(psi, n)) / sqrt(5);
    return static_cast<ll>(round(fn));
}


int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n;
        string s;
        cin >> s;
        n = (ll)s.length();
        deque<ll> st;
        multiset<ll> ms;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && (s[i]-'0') < st.back()) {
                ms.insert(min(9ll, st.back()+1));
                st.pop_back();
            }
            st.push_back(s[i]-'0');
        }

        while (!st.empty())
            ms.insert(st.front()), st.pop_front();
        for (auto ch : ms)
            cout << ch;
        cout << endl;
    }
    return 0;
}