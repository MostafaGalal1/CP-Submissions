#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10, M = 1e9 + 7;
bool visited[N];
map<ll, map<ll, bool>> arr;

ll pow(ll a, ll b, ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

ll dfs(ll node){
    ll num = 1ll;
    visited[node] = true;
    for (auto & child : arr[node]){
        if (!visited[child.first])
            num += dfs(child.first);
    }
    return num;
}

int main() {
    ll n, k, u, v, c, cnt;
    cin >> n >> k;

    cnt = pow(n, k, M);

    for (ll i = 0; i < n-1; ++i) {
        cin >> u >> v >> c;
        if (!c){
            arr[u][v] = true;
            arr[v][u] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ll num = dfs(i);
            cnt -= pow(num, k, M);
            cnt += M;
            cnt %= M;
        }
    }

    cout << cnt << endl;

    return 0;
}