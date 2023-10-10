#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second

#define Tsetso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const ll N = 2e5+10 , M = 23, oo = 1e18+7 , mod = 1e9+7, sqr = 450;
ll n ,m , dist[N] , par[N] ,price[N];
vector < pair < int , ll > > g[N];

void Dijkstra()
{
    priority_queue< pair < ll , int > > pq;
    for ( int i = 1 ; i <= n ; i++)
    {
        dist[i] = price[i];
        pq.push({-dist[i],i});
    }
    while(!pq.empty())
    {
        int node = pq.top().second ;
        ll distance = -pq.top().first;
        pq.pop();
        if(distance > dist[node])
            continue;
        for(auto ch : g[node])
        {
            if(dist[node] + 2 * ch.second < dist[ch.first])
            {
                par[ch.F] = node;
                dist[ch.first] = dist[node] + 2 * ch.second;
                pq.push({-dist[ch.first],ch.first});
            }
        }
    }
}
void testCase()
{
    cin >> n >> m ;
    for ( int i = 0 ; i < m ;i++)
    {
        ll u, v ,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for ( int i = 1 ; i <= n ; i++)
        cin >> price[i];
    Dijkstra();
    for ( int i = 1 ; i <= n ; i++)
        cout << dist[i] << ' ';;
    cout << '\n';;
}
int32_t main() {

    Tsetso
    int t = 1;
//    cin >> t;
    while(t--){
        testCase();
    }
}