#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define oo INFINITY
#define lp(i,n) for (int i = 0; i < n; i++)

int N = 1e5 + 5;
vector<vector<int>> roads(N);
vector<bool> isleaf(N, true);

bool tru = true;

void dfs(int x)
{
    int leafs = 0;
    if (isleaf[x]) return;
    for (int child : roads[x])
    {
        if (isleaf[child])
        {
            leafs++;
            continue;
        }
        dfs(child);
    }
    if (leafs < 3) tru = false;
}

// long looooooooooooooooooong
void solve(ll kkkk, ll tttt)
{
    int n; cin >> n;

    for (int i = 1; i < n; i++)
    {
        int x; cin >> x;x--; roads[x].push_back(i);
        isleaf[x] = false;
    }
    dfs(0);
    if (tru)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}


void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }


int main()
{
//    fast();
//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)

    int i = 1, t = 1;
        solve(t, i);
    return 0;
}
