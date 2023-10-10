#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7, N = 1e6+10, b1 = 29, b2 = 37;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll pref1[N], pw1[N], inv1[N], pref2[N], pw2[N], inv2[N];

ll add(ll a, ll b){
    return (a + b)%mod;
}

ll sub(ll a, ll b){
    return ((a - b)%mod + mod)%mod;
}

ll mul(ll a, ll b){
    return (a * b)%mod;
}

ll fp (ll a, ll p){
    if (p == 0)
        return 1;
    ll tmp = fp(a, p/2);
    tmp = mul(tmp, tmp);
    if (p&1)
        tmp = mul(a, tmp);
    return tmp;
}

void init(){
    pw1[0] = 1, inv1[0] = 1;
    pw2[0] = 1, inv2[0] = 1;
    ll mul_inv1 = fp(b1, mod-2);
    ll mul_inv2 = fp(b2, mod-2);

    for (int i = 1; i < N; ++i) {
        pw1[i] = mul(b1, pw1[i-1]);
        inv1[i] = mul(mul_inv1, inv1[i-1]);
        pw2[i] = mul(b2, pw2[i-1]);
        inv2[i] = mul(mul_inv2, inv2[i-1]);
    }
}

pair<ll, ll> genHash(string s) {
    ll val, res1 = 0, res2= 0;
    for (int i = 1; i <= s.length(); ++i) {
        val = s[i-1] - 'a' + 1;
        res1 = add(res1, mul(val, pw1[i-1]));
        res2 = add(res2, mul(val, pw2[i-1]));
    }
    return {res1, res2};
}

pair<ll, ll> getHash(ll l, ll r) {
    return {mul(sub(pref1[r], pref1[l]), inv1[l]), mul(sub(pref2[r], pref2[l]), inv2[l])};
}

int main()
{
    fast();
    init();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll val, n, c;
        string s;
        cin >> n >> c >> s;

        pref1[0] = pref2[0] = 0;
        for (int i = 1; i <= s.length(); ++i) {
            val = s[i - 1] - 'a' + 1;
            pref1[i] = add(pref1[i - 1], mul(val, pw1[i - 1]));
            pref2[i] = add(pref2[i - 1], mul(val, pw2[i - 1]));
        }

        set<pair<ll ,ll>> st;
        ll sz = (ll) s.length() - n;
        for (int i = 0; i <= sz; ++i) {
            pair<ll, ll> curHash = getHash(i, i + n);
            st.insert(curHash);
        }

        cout << st.size() << endl;
        if (t)
            cout << endl;;
    }

    return 0;
}
