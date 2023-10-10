#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 2, mod = 1e9 + 7;
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

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
void bfs(ll x, ll y, ll n, vector<string> &v){
    if ((x > 0 && x < n-1) && (y > 0 && y < n-1)){
        if (v[x][y-1] == '#' && v[x+1][y] == '#' && v[x][y+1] == '#' && v[x-1][y] == '#'){
            v[x][y-1] = v[x+1][y] = v[x][y+1] = v[x-1][y] = v[x][y] = '.';
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            if ((x+dx[i] > -1 && x+dx[i] < n) && (y+dy[i] > -1 && y+dy[i] < n) && v[x+dx[i]][y+dy[i]] == '#')
                bfs(x+dx[i], y+dy[i], n, v);
        }
    }
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

int lis(vector<int>& nums) {
    vector<int> piles;
    for (int num : nums) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        if (it == piles.end()) {
            piles.push_back(num);
        } else {
            *it = num;
        }
    }
    return piles.size();
}

vector<vector<ll>> divis(N);

void build()
{
    for (int i = 1; i < N; i++) {
        divis[i].push_back(i);
        for (int j = i * 2; j < N; j += i)
            divis[j].push_back(i);
    }
}

int main() {
    fast();
    ll n;
    cin >> n;
    vector<ll> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    bool z = false;
    ll neg = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0)
            res += a[i] - 1;
        else if (a[i] < 0) {
            res += -1 - a[i];
            neg++;
        } else {
            res++;
            z = true;
        }
    }

    if ((neg%2 && z) || !(neg%2))
        cout << res;
    else
        cout << res + 2;
    cout << endl;
    return 0;
}