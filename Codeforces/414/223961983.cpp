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

const ll N = 2e6+5, inf = LONG_MAX, mod = 998244353;
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

vector<bool> isPrime(2000001, true);
void sieveOfEratosthenes() {
    ll n = 2000000;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

vector<ll> linearSieve() {
    ll n = 10000000;
    vector<ll> lp(n + 1);
    vector<ll> pr;
    for (ll i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
            lp[i * pr[j]] = pr[j];
    }
    return lp;
}

double fibonacci(ll n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;
    double fn = (pow(phi, n) - pow(psi, n)) / sqrt(5);
    return round(fn);
}

vector<ll> divis(ll n) {
    vector<ll> r;
    for (ll i = 1; i <= (ll)sqrt(n); ++i) {
        if (n % i == 0) {
            r.push_back(i);
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

int main() {
    fast();
    ll t;
    //cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, k;
        cin >> n >> k;
        set<ll> s;

        for (int i = 1; i <= 1e6; ++i)
            s.insert(i);

        if (n == 1) {
            if (!k)
                cout << 1;
            else
                cout << -1;
        } else if (k - n/2 + 1 <= 0)
            cout << -1;
        else if (n > 1){
            k -= n/2 - 1;
            cout << k << ' ' << 2 * k << ' ';
            if (k <= (ll)1e6)
                s.erase(k);
            if (2 * k <= (ll)1e6)
                s.erase(2 * k);
            for (int i = 0; i < n / 2 - 1; ++i) {
                if (*s.begin() + 1 != *next(s.begin()))
                    i--, s.erase(s.begin());
                else {
                    cout << *s.begin() << ' ' << *next(s.begin()) << ' ';
                    s.erase(s.begin()), s.erase(s.begin());
                }
            }
            if (n%2)
                cout << *s.begin();
        } else
            cout << 1;
        cout << endl;
    }
    return 0;
}