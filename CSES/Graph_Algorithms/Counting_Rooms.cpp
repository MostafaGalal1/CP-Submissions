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

void rec (string r, multiset<char> ms, set<string>& si){
    if (ms.empty()){
        si.insert(r);
        return;
    }
    for (char m : ms) {
        multiset<char> ns = ms;
        ns.erase(ns.find(m));
        rec(r + m, ns, si);
        ns.insert(m);
    }
}

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
void dfs (ll n, ll m, ll x, ll y, vector<vector<char>>& a) {
    if (x < 0 || x > n-1 || y < 0 || y > m-1 || a[x][y] == '#')
        return;
    a[x][y] = '#';
    for (int i = 0; i < 4; ++i)
        dfs(n, m, x + dx[i], y + dy[i], a);
}

int main() {
    fast();
    ll t;
//    cin >> t;
    t = 1;

    while (t--) {
        ll n, m, cnt = 0;
        cin >> n >> m;
        vector<vector<char>> a(n ,vector<char>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] != '#')
                    dfs(n, m, i, j, a), cnt++;

        cout << cnt << endl;
    }

    return 0;
}