#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
const ll N = 1e5 + 5, mod = 1e9 + 7;
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

void dfs(ll node, vector<vector<ll>> &arr, vector<vector<ll>> &dp) {
    vis[node] = true;
    for (auto& ch : arr[node]) {
        if (!vis[ch])
            dfs(ch, arr, dp);
    }

    for (auto& ch : arr[node]) {
        dp[node][0] += max(dp[ch][0], dp[ch][1]);
        ll cnt = 0;
        for (auto& chh : arr[ch])
            cnt += max(dp[chh][0], dp[chh][1]);
        dp[node][1] = max(1 + dp[ch][0] + cnt, dp[node][1]);
    }
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

//ll mobius(ll N) {
//    if (N == 1)
//        return 1;
//
//    ll p = 0;
//    for (int i = 1; i <= N; i++) {
//        if (N % i == 0 && isPrime(i)) {
//
//            if (N % (i * i) == 0)
//                return 0;
//            else
//                p++;
//        }
//    }
//    return (p % 2 != 0)? -1 : 1;
//}

bool cmp(pair<ld, ll> a, pair<ld, ll> b){
    return a.first > b.first || (round(a.first * 100.0)/100 == round(b.first * 100.0)/100 && a.second < b.second);
}

ll mex(vector<ll> a){
    set<ll> s;
    ll n = (ll)a.size();

    for (int i = 0; i < n; ++i) {
        s.insert(a[i]);
    }

    ll cu = 0;
    for(auto ch : s){
        if (ch != cu)
            break;
        cu++;
    }

    return cu;
}

vector<ll> divisors(ll n) {
    vector<ll> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

//int lis(vector<int>& nums) {
//    vector<int> piles;
//    for (int num : nums) {
//        auto it = lower_bound(piles.begin(), piles.end(), num);
//        if (it == piles.end()) {
//            piles.push_back(num);
//        } else {
//            *it = num;
//        }
//    }
//    return piles.size();
//}

//vector<vector<ll>> divis(N);
//void build()
//{
//    for (int i = 1; i < N; i++) {
//        divis[i].push_back(i);
//        for (int j = i * 2; j < N; j += i)
//            divis[j].push_back(i);
//    }
//}

//void bubbleSort(vector<ll>& a, vector<ll> &b, vector<pair<ll, ll>> &res, ll n) {
//    bool swapped;
//    for (int i = 0; i < n - 1; ++i) {
//        swapped = false;
//        for (int j = 0; j < n - i - 1; ++j) {
//            if ((a[j] > a[j + 1] && b[j] >= b[j + 1]) || (a[j] >= a[j + 1] && b[j] > b[j + 1])) {
//                swap(a[j], a[j + 1]);
//                swap(b[j], b[j + 1]);
//                res.emplace_back(j+1, j+2);
//                swapped = true;
//            }
//        }
//        if (!swapped) {
//            break;
//        }
//    }
//}

//const int MAXN = 100005;
//ll color[MAXN];
//
//bool bipartite(int v, int c) {
//    color[v] = c;
//    for(int i = 0; i < adj[v].size(); i++) {
//        int u = adj[v][i];
//        if(color[u] == c) return false;
//        if(color[u] == 0 && !bipartite(u, -c)) return false;
//    }
//    return true;
//}

int main() {
    fast();
    ll t;
    cin >> t;

    while (t-->0){
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a;
        ll l = 1ll, r = 3*n;

        while (l < r){
            a.emplace_back(l, r);
            l+=3, r-=3;
        }

        cout << (ll)a.size() << endl;
        for (int i = 0; i < (ll)a.size(); ++i) {
            cout << a[i].first << ' ' << a[i].second << endl;
        }
    }
    return 0;
}