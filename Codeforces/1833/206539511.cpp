#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
const ll N = 2e5 + 5, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 3e5 + 10, inf = INT_MAX;

vector<ll> inStack;
vector<ll> a[N], loop;
vector<bool> visited, stck;
bool cycle;
vector<ll> cyc;

void dfsss(int node, int par){
    if(cycle) {
        return;
    }
    stck[node] = true;
    visited[node] = true;
    inStack.push_back(node);

    for(auto adj : a[node]){
        if(!visited[adj])
            dfsss(adj, 0);
        else if(stck[adj] && adj != par){
            cycle = true;
            ll num = 1;
            while(inStack.back() != adj){
                loop.push_back(inStack.back());
                num++;
                inStack.pop_back();
            }
            cyc.push_back(num);
            loop.push_back(adj);
        }
    }
    stck[node] = false;
    inStack.pop_back();
}

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, x;
        cin >> n;
        cyc = vector<ll>();
        visited = vector<bool> (n+1, false);
        stck = vector<bool> (n+1, false);

        for (int i = 0; i <= n; ++i) {
            a[i].clear();
        }

        for (int i = 1; i <= n; ++i) {
            cin >> x;
            a[i].push_back(x);
        }

        for (int i = 1; i <= n; ++i) {
            cycle = false;
            inStack.clear();
            if (!visited[i]){
                dfsss(i, 0);
            }
        }

        ll eds = 0;
        for (int i = 0; i < (ll)cyc.size(); ++i) {
            if (cyc[i] <= 2)
                eds++;
        }
        
        cout << (ll)cyc.size() - eds + (eds==0?0:1) << ' ' << (ll)cyc.size() << endl;
    }
    return 0;
}