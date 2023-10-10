#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7, N = 1e5+10, b1 = 59;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll pref1[N], pw1[N], inv1[N], prer1[N];

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

ll getHash1(ll l, ll r) {
    return mul(sub(pref1[r], pref1[l]), inv1[l]);
}

ll getHash2(ll l, ll r) {
    return mul(sub(prer1[r], prer1[l]), inv1[l]);
}

int main()
{
    fast();
    init();
    string s;

    while (cin >> s) {
        ll val1, val2;
        string rs = s;
        reverse(rs.begin(), rs.end());

        pref1[0] = prer1[0];
        for (int i = 1; i <= s.length(); ++i) {
            val1 = s[i - 1] - 'A' + 1, val2 = s[s.length() - i] - 'A' + 1;
            pref1[i] = add(pref1[i - 1], mul(val1, pw1[i - 1]));
            prer1[i] = add(prer1[i - 1], mul(val2, pw1[i - 1]));
        }

        ll ind = (ll)s.length(), sz = (ll) s.length();
        for (int i = 0; i <= sz; ++i) {
            ll pattHash = getHash1(i, (ll)rs.length());
            ll curHash = getHash2(0, (ll)s.length()-i);
            if (pattHash == curHash)
                break;
            else
                ind = (ll)s.length() - i - 1;
        }

        cout << s << rs.substr(ind, (ll)rs.length()-ind) << endl;;
    }

    return 0;
}
