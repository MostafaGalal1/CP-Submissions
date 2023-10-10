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

ll max_cats;
ll dfs(ll node, ll cats_no, vector<ll> &cats, vector<vector<ll>> &arr) {
    vis[node] = true;
    ll pt = 0;

    if (cats_no > max_cats)
        return 0;

    if (arr[node].size() == 1 && node)
        return 1;

    for (auto child : arr[node]) {
        if (!vis[child])
            pt += dfs(child, cats[child] + (cats[node] > 0? cats_no:0), cats, arr);
    }

    return pt;
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        bool done = false;
        vector<ll> a(n), red(64, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        if (a[0] != 1)
            done = true;

        ll reds;
        int i;
        for (i = 1; i < min(n, 63ll) && !done; ++i) {
            reds = 0;
            for (int j = 1; j < i; ++j)
                reds += red[j];

            if (a[i] <= (1ll<<(i-1)) - reds) {
                red[i] += (1ll<< (i - 1)) - reds - a[i];
                for (int j = 1; j < i; ++j)
                    red[j] *= 2;
            } else {
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}