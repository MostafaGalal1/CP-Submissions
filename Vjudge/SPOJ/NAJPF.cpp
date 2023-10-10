#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7, N = 1e6+10, b1 = 29;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll pref1[N], pw1[N], inv1[N];

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
    ll mul_inv1 = fp(b1, mod-2);
    for (int i = 1; i < N; ++i) {
        pw1[i] = mul(b1, pw1[i-1]);
        inv1[i] = mul(mul_inv1, inv1[i-1]);
    }
}

ll genHash(string s) {
    ll val, res = 0;
    for (int i = 1; i <= s.length(); ++i) {
        val = s[i-1] - 'a' + 1;
        res = add(res, mul(val, pw1[i-1]));
    }
    return res;
}

ll getHash(ll l, ll r) {
    return mul(sub(pref1[r], pref1[l]), inv1[l]);
}

int main()
{
    fast();
    init();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll val;
        string s, patt;
        cin >> s >> patt;

        ll pattHash = genHash(patt);

        pref1[0] = 0;
        for (int i = 1; i <= s.length(); ++i) {
            val = s[i - 1] - 'a' + 1;
            pref1[i] = add(pref1[i - 1], mul(val, pw1[i - 1]));
        }

        vector<ll> ve;
        ll sz = (ll) s.length() - (ll) patt.length();
        for (int i = 0; i <= sz; ++i) {
            ll curHash = getHash(i, i + (ll) patt.length());
            if (pattHash == curHash)
                ve.push_back(i + 1);
        }

        if (ve.empty())
            cout << "Not Found" << endl;
        else {
            cout << ve.size() << endl;
            for (int i = 0; i < ve.size(); ++i) {
                cout << ve[i] << ' ';
            }
            cout << endl;
        }
        cout << endl;;
    }

    return 0;
}
