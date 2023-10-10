#include <bits/stdc++.h>
using namespace std;

//#define oo INFINITY
//#define lp(i,f,n) for (int i = f; i < n; i++)

#define lp(i,a,b); for (int i = a; i < b; i++)
typedef long long ll;
typedef vector<vector<int>> vii;

int N = 1e5 + 5;
set<int> visited;
vii adjlist(N);
vector<set<int>> other(N);
queue<pair<int, int>> q;
vector<vector<int>> mem(N);
queue<int> answers;
void bfs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (other[i].size() == 0)
            q.push({i,0});
    }
    if (q.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    while(!q.empty())
    {
        int x=q.front().first, level = q.front().second; q.pop();
        mem[x].push_back(level);
        if (other[x].size() != 0)
            continue;
        if (visited.count(x)) continue;
        visited.emplace(x);
        answers.push(x);
        for(auto u:adjlist[x])
        {
            q.push({u, level + 1});
            other[u].erase(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited.count(i))
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
//
    }
    while (!answers.empty())
    {
        cout << answers.front() << endl;
        answers.pop();
    }
}


// long looooooooooooooooooong
bool solve(int kkkk, int tttt)
{
    visited.clear();
    adjlist.clear();
    vector<set<int>> empty(N);
    swap(other, empty);
    while(!q.empty())q.pop();
    mem.clear();
    //answers.clear();

    ll n,m;
    cin>>n>>m;
    if (n == 0 && m == 0)
        return false;
    for (int i = 0; i < m; i++)
    {
        ll  x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        other[y].emplace(x);
    }
    bfs(n);
    return true;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }


int main()
{

    //fast();
//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)

    int i = 1, t = 1;
    while (true)
        if (!solve(t, i))
            return 0;
    return 0;
}