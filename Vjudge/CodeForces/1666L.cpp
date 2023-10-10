#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll oo = LONG_LONG_MAX;
const ll N = 2e5+10;

vector<ll> arr[N];
vector<ll> dis(N, oo);
bool visited[N];
ll par[N], anc[N];

ll s, des = 0;
bool done = false, found = false;
deque<ll> q1;

void bfs(ll node){
    queue<ll> q;
    q.push(node);
    dis[node] = 0;
    par[node] = node;
    anc[node] = node;

    while (!q.empty()){
        node = q.front();
        q.pop();

        for(ll child : arr[node]) {
            if (dis[child] > dis[node] + 1) {
                par[child] = node;
                if (arr[node].size() > 1)
                    anc[child] = node;
                else
                    anc[child] = anc[node];
                dis[child] = dis[node] + 1;
                q.push(child);
            } else if (child != s && child != par[node] &&
                       (anc[child] != anc[node] || (anc[child] == anc[node] && anc[node] == s))) {
                done = true;

                des = child;

                ll cur = child;
                deque<ll> de, db;
                while (par[cur] != cur){
                    visited[cur] = true;
                    de.push_back(cur);
                    cur = par[cur];
                }
                de.push_back(s);

                cur = node;
                db.push_back(child);
                while (par[cur] != cur){
                    if (visited[cur]){
                        done = false;
                        de.clear();
                        db.clear();
                        for (int i = 0; i <= N; ++i) {
                            visited[i] = false;
                        }
                        break;
                    }
                    db.push_back(cur);
                    cur = par[cur];
                }
                
                if (!done)
                    continue;
                db.push_back(s);

                cout << "Possible" << endl;
                ll sz1 = de.size();
                cout << sz1 << endl;
                for (int i = 0; i < sz1; ++i) {
                    cout << de.back() << ' ';
                    de.pop_back();
                }
                cout << endl;


                ll sz2 = db.size();
                cout << sz2 << endl;
                for (int i = 0; i < sz2; ++i) {
                    cout << db.back() << ' ';
                    db.pop_back();
                }

                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;
    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        arr[u].push_back(v);
    }

    if (arr[s].size() > 1)
        bfs(s);

    if (!done)
        cout << "Impossible";
    cout << endl;

    return 0;
}