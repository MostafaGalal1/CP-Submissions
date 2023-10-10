#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b){
    return (1LL * a * b)%mod;
}

ll add(ll a , ll b){
    return a + b %mod;
}

ll fp( ll b , ll p){
    if (p < 0)
        return 0;
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
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

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<pair<ll, ll>> a(n);
        vector<ll> b;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i+1;
        }
        sort(a.begin(), a.end());
        ll si, sii, ri, rii;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                b.push_back(a[i].first+a[j].first);
            }
        }
        sort(b.begin(), b.end());

        bool done = false;
        ll m = n*(n-1)/2;
        for (int i = 0; i < m; ++i) {
            auto it = lower_bound(b.begin()+i+1, b.end(), x-b[i]);
            if (it != b.end() && *it + b[i] == x){
                ll s1 = b[i], s2 = *it;
                for (int j = 0; j < n; ++j) {
                    auto is = lower_bound(a.begin()+j+1, a.end(), make_pair(s1 - a[j].first, 0ll));
                    if (is != a.end() && is->first + a[j].first == s1){
                        si = j;
                        sii = is-a.begin();
                        break;
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (j != si && j != sii) {
                        auto is = lower_bound(a.begin() + j + 1, a.end(), make_pair(s2 - a[j].first, 0ll));
                        if (is != a.end() && is->first + a[j].first == s2) {
                            while (is != a.end() && (is-a.begin() == si || is-a.begin() == sii)){
                                is = next(is);
                            }
                            if (is != a.end() && is-a.begin() != si && is-a.begin() != sii && is->first + a[j].first == s2) {
                                done = true;
                                ri = j;
                                rii = is - a.begin();
                                break;
                            }
                        }
                    }
                }
                if (done){
                    cout << a[si].second << ' ' << a[sii].second << ' ' << a[ri].second << ' ' << a[rii].second;
                    break;
                }
            }
        }

        if (!done)
            cout << "IMPOSSIBLE";
        cout << endl;
    }

    return 0;
}