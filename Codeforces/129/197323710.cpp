#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 1000 + 10, inf = INT_MAX;

vector<bool> vis(siz);
vector<ld> dis(siz);

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

ll dfs(ll node, vector<vector<ll>> &arr) {
    vis[node] = true;
    ll mx = 0;

    for (auto child : arr[node]) {
        if (!vis[child])
            mx = max(mx, dfs(child, arr) + 1);
    }

    return mx;
}

pair<ll, ll> dfs1(ll node, vector<vector<ll>> &arr) {
    vis[node] = true;
    pair<ll, ll> mx = {node, 0};

    for (auto child : arr[node]) {
        if (!vis[child]) {
            pair<ll, ll> op = dfs1(child, arr);
            if (mx.second < op.second){
                mx.first = op.first;
                mx.second = op.second;
            }
        }
    }

    mx.second++;
    return mx;
}

ll dfs2(ll node, vector<vector<ll>> &arr) {
    vis[node] = false;
    ll mx = 0;

    for (auto child : arr[node]) {
        if (vis[child])
            mx = max(mx, dfs2(child, arr) + 1);
    }

    return mx;
}

set<ll> cyc;

void dfs_cycle(ll u, ll p, vector<int> &color, vector<ll> &par, vector<vector<ll>> &a)
{
    if (color[u] == 2) {
        return;
    }

    if (color[u] == 1) {
        vector<ll> v;

        ll cur = p;
        v.push_back(cur);

        while (cur != u) {
            cur = par[cur];
            v.push_back(cur);
        }
        for (long long & i : v) {
            cyc.insert(i);
        }
        return;
    }
    par[u] = p;
    color[u] = 1;

    for (int v : a[u]) {
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, a);
    }
    color[u] = 2;
}

int main() {
    ll n, m, x, y;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>());

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> color(n);
    vector<ll> par(n);

    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs_cycle(i, -1, color, par, a);
    }

    for (int i = 0; i < n; ++i) {
        vis[i] = false;
    }

    for (long long i : cyc) {
        vis[i] = true;
    }

    ll res = 0;
    for (long long i : cyc) {
        vis[i] = false;
        res = max(res, dfs(i, a));
    }

    for (int i = 0; i < n; ++i) {
        if (a[i].size() == 1 && !vis[i])
            res = max(res, (dfs2(dfs1(i, a).first, a)+1) / 2);
    }

    cout << res << endl;

    return 0;
}