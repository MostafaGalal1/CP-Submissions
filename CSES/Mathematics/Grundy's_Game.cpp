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

ll mul( ld a,  ld b){
    return fmod(a * b, mod);
}

ll add( ll a , ll b){
    return (a % mod + b % mod) + mod %mod;
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

ld inv(ld i){
    return i <= 1 ? i : mod - (mod/i) * fmod(inv(fmod(mod, i)), mod);
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

ll mex(vector<ll> v){
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != i)
            return i;
    }
    return (ll)v.size();
}

vector<ll> gr(2001, -1);
ll grundy(ll n){
    vector<ll> g;
    for (int i = 1; i <= n/2; ++i) {
        if (i != n-i)
            g.push_back((gr[i] == -1 ? grundy(i) : gr[i]) ^ (gr[n - i] == -1 ? grundy(n - i) : gr[n - i]));
    }
    return gr[n] = mex(g);
}

int main() {
    fast();
    ll t;
    cin >> t;
    gr[0] = gr[1] = gr[2] = 0;
    grundy(2000);

    while (t --> 0) {
        ll n;
        cin >> n;
        if (n > 2000 || gr[n])
            cout << "first";
        else
            cout << "second";
        cout << endl;
    }
    return 0;
}