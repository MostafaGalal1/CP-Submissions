#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 105, mod = 998244353;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

ll mul( ll a,  ll b)
{
    return 1LL * a * b %mod;
}
ll add( ll a , ll b)
{
    return (a + b) %mod;
}
ll fp( ll b , ll p){
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 1; i <= n; ++i)
        res = mul(res, i);
    return res;
}

ll inv(ll i) {
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(n-1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-1; ++j) {
                cin >> a[i][j];
            }
        }
        
        ll f = -1, s = -1, fc = 0, sc = 0, cur = -1;

        for (int i = 0; i < n; ++i) {
            if (f == -1)
                f = a[i][0];
            else if (s == -1 && f != a[i][0])
                s = a[i][0];

            if (f == a[i][0])
                fc++;
            else if (s == a[i][0])
                sc++;
        }


        if (fc > sc) {
            cout << f << ' ';
            cur = s;
        } else if (fc < sc) {
            cout << s << ' ';
            cur = f;
        }

        for (int i = 1; i < n-1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cur != a[j][i]){
                    cout << cur << ' ';
                    cur = a[j][i];
                    break;
                }
            }
        }

        cout << cur << endl;
    }
}