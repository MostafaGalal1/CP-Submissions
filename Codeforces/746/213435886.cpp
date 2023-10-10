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
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, k, o = 0, e = 0, cnt = 0;
        cin >> n >> k;
        set<ll> os, es, ss;
        map<ll, ll> mapp;

        for (int i = 1; i <= 1e6+5; ++i) {
            if (i%2)
                os.insert(i);
            else
                es.insert(i);
        }

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mapp[a[i]]++;
            if (a[i]%2)
                o++, os.erase(a[i]);
            else
                e++, es.erase(a[i]);
        }

        bool done = false;
        for (auto& m : mapp) {
            while (m.second > 1){
                if (m.first%2) {
                    cnt++;
                    ll nu;
                    if (o*1.0/e>1) {
                        nu = *es.begin();
                        es.erase(es.begin());
                        o--;
                        e++;
                    } else {
                        nu = *os.begin();
                        os.erase(os.begin());
                    }
                    if (nu > k){
                        done = true;
                        break;
                    }
                    mapp[nu]++;
                    ss.insert(nu);
                    m.second--;
                } else if (m.first%2==0) {
                    cnt++;
                    ll nu;
                    if (e*1.0/o>1) {
                        nu = *os.begin();
                        os.erase(os.begin());
                        e--;
                        o++;
                    } else {
                        nu = *es.begin();
                        es.erase(es.begin());
                    }
                    if (nu > k){
                        done = true;
                        break;
                    }
                    mapp[nu]++;
                    ss.insert(nu);
                    m.second--;
                }
            }
        }

        for (auto& m : mapp) {
            if (o > e && m.first%2) {
                cnt++;
                ll nu;
                o--, e++;
                nu = *es.begin();
                es.erase(es.begin());
                if (nu > k){
                    done = true;
                    break;
                }
                ss.insert(nu);
            } else if (o < e && m.first%2==0) {
                cnt++;
                ll nu;
                e--, o++;
                nu = *os.begin();
                os.erase(os.begin());
                if (nu > k){
                    done = true;
                    break;
                }
                ss.insert(nu);
            } else {
                ss.insert(m.first);
            }
        }

        if (done)
            cout << -1 << endl;
        else {
            cout << cnt << endl;
            vector<ll> ans(n, 0);
            for (int i = 0; i < n; ++i) {
                if (ss.find(a[i]) != ss.end()) {
                    ans[i] = a[i];
                    ss.erase(a[i]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (!ans[i]) {
                    ans[i] = *ss.begin();
                    ss.erase(ss.begin());
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}