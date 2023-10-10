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

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> va(a), vb(b), vc(c);

        for (ll i = 0; i < a; ++i) {
            cin >> va[i];
        }
        for (ll i = 0; i < b; ++i) {
            cin >> vb[i];
        }
        for (ll i = 0; i < c; ++i) {
            cin >> vc[i];
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        sort(vc.begin(), vc.end());

        ll res = LONG_LONG_MAX;
        for (int i = 0; i < a; ++i) {
            auto itb = upper_bound(vb.begin(), vb.end(), va[i]);
            auto itc = upper_bound(vc.begin(), vc.end(), va[i]);

            if (!(itb == vb.end() || itc == vc.end()))
                res = min(res, (va[i] - *itb) * (va[i] - *itb) + (va[i] - *itc) * (va[i] - *itc) + (*itb - *itc) * (*itb - *itc));
            if (!(itb == vb.end() || itc == vc.begin())) {
                itc--;
                res = min(res, (va[i] - *itb) * (va[i] - *itb) + (va[i] - *itc) * (va[i] - *itc) + (*itb - *itc) * (*itb - *itc));
                itc++;
            }
            if (!(itb == vb.begin() || itc == vc.end())) {
                itb--;
                res = min(res, (va[i] - *itb) * (va[i] - *itb) + (va[i] - *itc) * (va[i] - *itc) + (*itb - *itc) * (*itb - *itc));
                itb++;
            }
            if (!(itb == vb.begin() || itc == vc.begin())) {
                itb--, itc--;
                res = min(res, (va[i] - *itb) * (va[i] - *itb) + (va[i] - *itc) * (va[i] - *itc) + (*itb - *itc) * (*itb - *itc));
            }
        }

        for (int i = 0; i < b; ++i) {
            auto ita = upper_bound(va.begin(), va.end(), vb[i]);
            auto itc = upper_bound(vc.begin(), vc.end(), vb[i]);

            if (!(ita == va.end() || itc == vc.end()))
                res = min(res, (vb[i] - *ita) * (vb[i] - *ita) + (vb[i] - *itc) * (vb[i] - *itc) + (*ita - *itc) * (*ita - *itc));
            if (!(ita == va.end() || itc == vc.begin())) {
                itc--;
                res = min(res, (vb[i] - *ita) * (vb[i] - *ita) + (vb[i] - *itc) * (vb[i] - *itc) + (*ita - *itc) * (*ita - *itc));
                itc++;
            }
            if (!(ita == va.begin() || itc == vc.end())) {
                ita--;
                res = min(res, (vb[i] - *ita) * (vb[i] - *ita) + (vb[i] - *itc) * (vb[i] - *itc) + (*ita - *itc) * (*ita - *itc));
                ita++;
            }
            if (!(ita == va.begin() || itc == vc.begin())) {
                ita--, itc--;
                res = min(res, (vb[i] - *ita) * (vb[i] - *ita) + (vb[i] - *itc) * (vb[i] - *itc) + (*ita - *itc) * (*ita - *itc));
            }
        }

        for (int i = 0; i < c; ++i) {
            auto ita = upper_bound(va.begin(), va.end(), vc[i]);
            auto itb = upper_bound(vb.begin(), vb.end(), vc[i]);

            if (!(ita == va.end() || itb == vb.end()))
                res = min(res, (vc[i] - *ita) * (vc[i] - *ita) + (vc[i] - *itb) * (vc[i] - *itb) + (*ita - *itb) * (*ita - *itb));
            if (!(ita == va.end() || itb == vb.begin())) {
                itb--;
                res = min(res, (vc[i] - *ita) * (vc[i] - *ita) + (vc[i] - *itb) * (vc[i] - *itb) + (*ita - *itb) * (*ita - *itb));
                itb++;
            }
            if (!(ita == va.begin() || itb == vb.end())) {
                ita--;
                res = min(res, (vc[i] - *ita) * (vc[i] - *ita) + (vc[i] - *itb) * (vc[i] - *itb) + (*ita - *itb) * (*ita - *itb));
                ita++;
            }
            if (!(ita == va.begin() || itb == vb.begin())) {
                ita--, itb--;
                res = min(res, (vc[i] - *ita) * (vc[i] - *ita) + (vc[i] - *itb) * (vc[i] - *itb) + (*ita - *itb) * (*ita - *itb));
            }
        }

        cout << res << endl;
    }
    return 0;
}