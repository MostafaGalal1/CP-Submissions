#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 1e5 + 10, inf = INT_MAX;

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

void dfs(ll node, vector<vector<ll>> &arr){
    vis[node] = true;
    for (auto child : arr[node]){
        if (!vis[child]) {
            dfs(child, arr);
            if (node)
                dis[node] += dis[child] / (arr[node].size() - 1);
            else
                dis[node] += dis[child] / arr[node].size();
        }
    }

    if (node)
        dis[node] += 1;
}

ll rec(ll n, ll lvl, bool mul){
    if (n%32768 == 0)
        return 0;
    if (lvl == 15)
        return 15;
    ll mn1 = (mul?rec(n + 1, lvl+1, true):15), mn2 = rec(n * 2, lvl+1, false);
    return min(mn1, mn2) + 1;
}

int main() {
    ll n, num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        cout << rec(num, 0, true) << " ";
    }
    cout << endl;

    return 0;
}