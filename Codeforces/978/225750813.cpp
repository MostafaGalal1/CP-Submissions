#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

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

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

bool canChooseKNumbers(ll n, ll k, ll x) {
    // Check for edge cases
    if (k > n) {
        return false;
    }
    if (k == 1) {
        return (x >= 1 && x <= n);
    }

    // Create a vector to store the chosen numbers
    std::vector<ll> chosen;

    // Start with the largest possible number
    ll current = n;

    // Calculate the sum of chosen numbers and add them to the vector
    ll sum = 0;
    while (chosen.size() < k - 1) {
        if (sum + current < x) {
            sum += current;
            chosen.push_back(current);
        }
        current--;
    }

    // Calculate the last number needed to reach x
    ll last = x - sum;

    // Check if the last number is within the valid range
    if (last >= 1 && last < current) {
        chosen.push_back(last);
        return true;
    }

    return false;
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t --> 0) {
        ll n, w;
        cin >> n >> w;

        vector<ll> v(n);
        for (ll i = 0; i < n; ++i)
            cin >> v[i];

        ll mx = w, mn = 0;

        bool done = false;
        if (abs(v[0]) > w)
            done = true;
        mx = min(mx, w-v[0]);
        mn = max(mn, -v[0]);
        for (int i = 1; i < n && !done; ++i) {
            v[i] += v[i - 1];
            if (abs(v[i]) > w){
                done = true;
                break;
            }
            mx = min(mx, w-v[i]);
            mn = max(mn, -v[i]);
        }

        cout << (done?0:max(mx - mn + 1, 0ll)) << endl;
    }
    return 0;
}