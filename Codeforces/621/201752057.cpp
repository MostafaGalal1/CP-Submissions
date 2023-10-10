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
    ll n;
    cin >> n;
    ll v, u;
    vector<ll> a(1999, 0), b(1999, 0);

    for (int i = 0; i < n; ++i) {
        cin >> v >> u;
        v--, u--;
        a[v+u]++;
        b[999-v+u]++;
    }

    ll res = 0;
    for (int i = 0; i < 1999; ++i)
        res += a[i]*(a[i]-1)/2 + b[i]*(b[i]-1)/2;

    cout << res << endl;
    return 0;
}