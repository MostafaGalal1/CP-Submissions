#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 3e5 + 10, inf = INT_MAX;

vector<bool> vis(siz, false);
vector<ll> dis(siz, inf);

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
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp %mod;
}

ll fact(ll n){
    ll res = 1;
    for (int i = 1; i <= n; ++i)
        res = mul(res, i);
    return res;
}

ll inv(ll i){
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

ll func (ll n, ll k, vector<ll> & a){
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
        sum += min(a[j], k);
    }
    return sum;
}


void bfs(ll node, vector<vector<ll>> &arr){
    queue<ll> q;
    q.push(node);
    dis[node] = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for(auto child : arr[node]){
            if (dis[node] + 1 < dis[child]) {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }
}

bool dfs(ll node, vector<vector<ll>> &arr) {
    vis[node] = true;

    for (auto child : arr[node]) {
        if (!vis[child])
            dfs(child, arr);
        else
            return true;
    }

    return false;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll mobius(ll N) {
    if (N == 1)
        return 1;

    ll p = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0 && isPrime(i)) {

            if (N % (i * i) == 0)
                return 0;
            else
                p++;
        }
    }
    return (p % 2 != 0)? -1 : 1;
}

bool cmp(pair<ld, ll> a, pair<ld, ll> b){
    return a.first > b.first || (round(a.first * 100.0)/100 == round(b.first * 100.0)/100 && a.second < b.second);
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, va;
        map<ll, ll> mapp;
        cin >> n;
        vector<ll> ve(n);
        bool od = (n % 2 == 1);

        vector<ll> res(n, -1);
        set<ll> s, l;

        ve[0] = (ll) ceil(n / 2.0);
        bool xo = od;
        for (int i = 1; i < n; ++i) {
            if (xo)
                ve[i] = ve[i-1] - i;
            else
                ve[i] = ve[i-1] + i;
            xo ^= true;
        }
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        cout << "+ " << n + 1 << endl;
        cout.flush();
        cin >> va;
        if (va == -2)
            return 0;

        cout << "+ " << n << endl;
        cout.flush();
        cin >> va;
        if (va == -2)
            return 0;

        for (int i = 0; i < n; ++i) {
            mapp[ve[i]] = ve[n-1-i];
        }
        cout << endl;
        ll c, k;
        set<pair<ll, ll>> se;
        for (int i = 2; i <= n; ++i) {
            cout << "? " << 1 << ' ' << i << endl;
            cout.flush();
            cin >> va;
            if (va == -2)
                return 0;
            else {
                se.insert({va, i});
            }
        }

        if (se.size() > 1){
            if (se.begin()->first == 1 && next(se.begin())->first == 1) {
                cout << "? " << prev(se.end())->second << ' ' << se.begin()->second << endl;
                cout.flush();
                cin >> va;
                if (va == -2)
                    return 0;
                else {
                    c = prev(se.end())->second;
                    if (va == n - 1) {
                        k = se.begin()->second;
                    } else {
                        k = next(se.begin())->second;
                    }
                }
            } else {
                c = prev(se.end())->second;
                k = 1;
            }
        } else {
            c = 2;
            k = 1;
        }

        res[c - 1] = (ll) ceil(n / 2.0);
        s.erase(res[c - 1]);

        for (int i = 1; i < n && s.size() > 1; ++i) {
            if (i != c) {
                cout << "? " << c << ' ' << i << endl;
                cout.flush();
                cin >> va;
                if (va == -2)
                    return 0;

                if (!od) {
                    res[i - 1] = res[c - 1] + (va % 2 == 1 ? (ll) ceil(va / 2.0) : -va / 2);
                    s.erase(res[c - 1] + (va % 2 == 1 ? (ll) ceil(va / 2.0) : -va / 2));
                } else {
                    res[i - 1] = res[c - 1] + (va % 2 == 1 ? -(ll) ceil(va / 2.0) : va / 2);
                    s.erase(res[c - 1] + (va % 2 == 1 ? -(ll) ceil(va / 2.0) : va / 2));
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (res[i] == -1) {
                res[i] = *s.begin();
                break;
            }
        }

        cout << "! ";
        for (int i = 0; i < n; ++i) {
            cout << res[i] << ' ';
        }

        for (int i = 0; i < n; ++i) {
            cout << mapp[res[i]] << ' ';
        }
        cout << endl;
        cout.flush();

        cin >> va;
        if (va == -2)
            return 0;
    }

    return 0;
}