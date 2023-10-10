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

const ll N = 2e5+5, inf = LONG_MAX, mod = 1e9+7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll add ( ll a , ll b)
{
    return (a + b) % mod;
}
ll mul ( ll a , ll b)
{
    return 1LL * a * b % mod;
}

ll fp( ll b , ll p)
{
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

ll fact[N], inv[N];
void build()
{
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    for (ll i = 2; i < N; i++)
        inv[i] = inv[i] * inv[i - 1] % mod;
}
ll nCr( ll n , ll r)
{
    return mul(fact[n],mul(inv[n-r],inv[r]));
}
ll nPr(ll n, ll r)
{
    ll ans = nCr(n, r); ans *= fact[r];
    ans %= mod;
    return ans;
}

ll mex(deque<ll> a){
    set<ll> s;
    ll n = (ll)a.size();

    for (int i = 0; i < n; ++i)
        s.insert(a.front()), a.pop_front();

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

ll fibonacci(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    double fn = (pow(phi, n) - pow(psi, n)) / sqrt(5);
    return static_cast<ll>(round(fn));
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

ll src;
ll dfs(ll u, ll p, ll dis, vector<vector<ll>>& adj, vector<ll>& ev, vector<ll>& in) {
    ll cnt = 0, num;
    bool f = true;
    for (auto v : adj[u]) {
        if (v != p) {
            num = dfs(v, u, dis+1, adj, ev, in);
            if (num == 1 && f)
                cnt++, f = false;
            else if (num != 1)
                cnt += num;
        }
    }
    if (!cnt)
        ev.push_back(dis);
    if (p == src && f)
        cnt++;
    return (u==src)?cnt:cnt+1;
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll n, res = 0;
        string s;
        cin >> n >> s;

        if (n%2)
            cout << -1;
        else {
            bool done = false;
            map<char, ll> m, cnt;
            for (int i = 0; i < n/2; ++i) {
                if (s[i] == s[n-1-i])
                    m[s[i]]++;
                cnt[s[i]]++;
                cnt[s[n-1-i]]++;
                if (cnt[s[i]] > n/2 || cnt[s[n-1-i]] > n/2) {
                    done = true;
                    break;
                }
            }

            if (done)
                cout << -1;
            else {
                multiset<ll> ms;
                for (auto mm : m)
                    ms.insert(mm.second);

                while ((ll)ms.size() > 1){
                    ll val1 = *prev(ms.end()), val2 = *prev(prev(ms.end()));
                    ms.erase(prev(ms.end()));
                    ms.erase(prev(ms.end()));
                    if (val1 > 1)
                        ms.insert(val1-1);
                    if (val2 > 1)
                        ms.insert(val2-1);
                    res++;
                }

                cout << res + (ms.empty()?0ll:*ms.begin());
            }
        }
        cout << endl;
    }
    return 0;
}