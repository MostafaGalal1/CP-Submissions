#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;

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

ll mex(vector<ll> a){
    set<ll> s;
    ll n = (ll)a.size();

    for (int i = 0; i < n; ++i)
        s.insert(a[i]);

    ll cu = 0;
    for(auto ch : s){
        if (ch != cu)
            break;
        cu++;
    }

    return cu;
}

bool compareBySize(const vector<ll>& vec1, const vector<ll>& vec2) {
    return vec1.size() > vec2.size();
}

vector<vector<ll>> sieveOfEratosthenes(ll n) {
    vector<bool> isPrime(n + 1, true);
    vector<vector<ll>> factors(n+1);
    for (int i = 2; i * i <= n; i++) {
        factors[i].push_back(i);
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
                factors[j].push_back(i);
                factors[i].push_back(j);
            }
        }
    }
    return factors;
}

vector<ll> dis(3e5+10, inf), par(3e5+10);
void bfs(ll node, vector<vector<ll>> &v, map<ll,bool> &m){
    for (int i = 0; i < 3e5+10; ++i) {
        par[i] = i;
    }
    queue<ll> q;
    q.push(node);
    dis[node] = 1;
    map<ll, bool> h;

    while (!q.empty()) {
        node = q.front();
        q.pop();

        for(auto child : v[node]){
            if (m[node] && m[child] && dis[child] > dis[node] + 1) {
                par[child] = node;
                dis[child] = dis[node] + 1;
                q.push(child);
            } else if (m[node] && (!m[child] && child < node) && dis[child] > dis[node]) {
                par[child] = node;
                dis[child] = dis[node];
                q.push(child);
            } else if (!m[node] && m[child] && dis[child] > dis[par[node]] + 1){
                par[child] = par[node];
                dis[child] = dis[par[node]] + 1;
                q.push(child);
            }
        }
    }
}

bool vis[N];
ll dfs(ll node, vector<vector<ll>> &adj, vector<ll> &val){
    vis[node] = true;
    for (auto child : adj[node]){
        if (!vis[child])
            val[node] += dfs(child, adj, val);
    }
    if (!val[node])
        val[node]++;
    return val[node];
}

vector<ll> divi(ll n, ll num) {
    vector<ll> divisors;
    for (int i = 2; i * i < num; i++) {
        if (num % i == 0 && i != n/num && num/i != n/num) {
            divisors.push_back(i);
            if (i != num/i)
                divisors.push_back(num/i);
        }
    }

    return divisors;
}

map<ll, ll> prime_factorize(ll n) {
    map<ll, ll> factors;
    ll i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            factors[i]++;
        } else {
            i++;
        }
    }

    if (n > 1) {
        factors[n]++;
    }

    return factors;
}

void insertSorted(deque<ll>& sortedArray, ll element) {
    auto it = lower_bound(sortedArray.begin(), sortedArray.end(), element);
    sortedArray.insert(it, element);
}

struct Point {
    ll x, y;
};

ll direction(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool areCollinearAndOverlapping(Point a1, Point b1, Point a2, Point b2) {
    if (direction(a1, b1, a2) == 0) {
        if (a2.x <= max(a1.x, b1.x) && a2.x >= min(a1.x, b1.x) && a2.y <= max(a1.y, b1.y) && a2.y >= min(a1.y, b1.y)) {
            return true;
        }
    }
    return false;
}

bool isintersect(Point a1, Point b1, Point a2, Point b2) {
    ll d1 = direction(a1, b1, a2);
    ll d2 = direction(a1, b1, b2);
    ll d3 = direction(a2, b2, a1);
    ll d4 = direction(a2, b2, b1);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    }

    if (areCollinearAndOverlapping(a1, b1, a2, b2) || areCollinearAndOverlapping(a2, b2, a1, b1)) {
        return true;
    }

    return false;
}

ld overlappingLength(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    // Calculate the intersection points
    ld intersectX1 = max(x1, x3);
    ld intersectY1 = max(y1, y3);
    ld intersectX2 = min(x2, x4);
    ld intersectY2 = min(y2, y4);

    // Check if the segments actually overlap
    if (intersectX1 <= intersectX2 && intersectY1 <= intersectY2) {
        // Calculate the length of the overlapping portion
        return std::sqrt((intersectX2 - intersectX1) * (intersectX2 - intersectX1)
                         + (intersectY2 - intersectY1) * (intersectY2 - intersectY1));
    }

    return 0.0;
}

int lis(vector<int>& nums) {
    vector<int> dp;
    for (int num : nums) {
        auto it = std::lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return dp.size();
}

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n;
        cin >> n;
        bool done = false;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i] || (b[i] - b[(i+1)%n] > 1 && a[i] < b[i])){
                done = true;
                break;
            }
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }

    return 0;
}