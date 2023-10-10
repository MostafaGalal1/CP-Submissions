#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9+7, N = 1e6+10, b1 = 17, b2 = 23;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll pref1[N][12], pref2[N][12], pw1[N], pw2[N];

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
    pw1[0] = 1, pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = mul(b1, pw1[i-1]);
        pw2[i] = mul(b2, pw2[i-1]);
    }
}

int main()
{
    fast();
    init();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll val, n;
        bool done = false;
        cin >> n;
        vector<string> s(n);
        map<pair<ll, ll>, bool> mapp;

        for (int i = 0; i < n; ++i)
            cin >> s[i];

        sort(s.begin(), s.end());

        for (int i = 0; i < n && !done; ++i) {
            pref1[i][0] = pref2[i][0] = 0;
            for (int j = 1; j <= s[i].length(); ++j) {
                val = s[i][j - 1] - '0' + 1;
                pref1[i][j] = add(pref1[i][j - 1], mul(val, pw1[j - 1]));
                pref2[i][j] = add(pref2[i][j - 1], mul(val, pw2[j - 1]));

                if (mapp[{pref1[i][j], pref2[i][j]}]) {
                    done = true;
                    break;
                }
            }

            mapp[{pref1[i][s[i].length()], pref2[i][s[i].length()]}] = true;
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }

    return 0;
}
