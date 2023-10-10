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

void dfs(ll node, ll p, vector<ll> &s, vector<vector<ll>> &arr) {
    vis[node] = true;
    for (auto child : arr[node]) {
        if (!vis[child])
            dfs(child, node,s, arr);
    }

    ll sum = 0;
    for (long long i : arr[node]) {
        if (i != p){
            sum += s[i];
        }
    }

    s[node] = sum + 1;
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        ll cnt = 0;
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != a[n-i-1][n-j-1]){
                    cnt++;
                }
            }
        }

        if (n%2){
            for (int i = 0; i < n/2; ++i) {
                if (a[n/2][i] != a[n/2][n-i-1])
                    cnt++;
            }
        }

        m -= cnt;
        if (m >= 0 && (m%2 == 0 || n%2 == 1)) {
            cout << "YES";
        } else
            cout << "NO";
        cout << endl;
    }
    return 0;
}