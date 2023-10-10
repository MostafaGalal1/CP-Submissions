#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 10;
ll par[N];
ll sz[N];

struct edge{
    ll start, end, cost;
};

void init(){
    for (ll i = 0; i < N; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

ll fpar(ll j){
    if (j == par[j])
        return j;
    return par[j] = fpar(par[j]);
}

void conn(ll u, ll v){
    u = fpar(u);
    v = fpar(v);
    if (u != v) {
        if (sz[u] > sz[v])
            par[v] = u, sz[u] += sz[v], sz[v] = 0;
        else
            par[u] = v, sz[v] += sz[u], sz[u] = 0;
    }
}

bool cmp(edge e1, edge e2) {
    return e1.cost < e2.cost;
}

int main() {
    ll n;
    while(scanf("%dll", &n) != EOF) {
        ll u, p, c, cost = 0;
        init();

        vector<edge> arr;

        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                cin >> c;
                if (i < j) {
                    edge e = {i, j, c};
                    arr.push_back(e);
                }
            }
        }

        sort(arr.begin(), arr.end(), cmp);

        for (int i = 0; i < arr.size(); i++) {
            u = fpar(arr[i].start), p = fpar(arr[i].end);
            if (u == p)
                continue;
            conn(u, p);
            cost += arr[i].cost;
        }

        cout << cost << endl;
    }
    return 0;
}