#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
vector<vector<ll>> g(N);
vector<bool> visited(N);
ll cnt = 0;

void dfs(ll node){
    visited[node] = true;
    for (ll ch : g[node]){
        if (!visited[ch])
            dfs(ch);
    }

    ll n = (ll)g[node].size();
    cnt += n * (n-1) / 2;
}

int main() {
    fast();
    ll n, v, w;
    cin >> n;

    for (int i = 0; i < n-1; ++i) {
        cin >> v >> w;
        v--, w--;
        g[v].push_back(w);
        g[w].push_back(v);
    }

    dfs(0);

    if (n < 3)
        cout << 0;
    else
        cout << cnt;
    cout << endl;

    return 0;
}