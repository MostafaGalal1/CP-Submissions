#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC optimize(3 , "Ofast" , "inline")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <bitset>
#include <deque>
using namespace std ;
#define ios ios::sync_with_stdio(false) , cin.tie(0)
#define x first
#define y second
#define pb push_back
#define ls rt << 1
#define rs rt << 1 | 1
typedef long long ll ;
const double esp = 1e-6 , pi = acos(-1) ;
typedef pair<int , int> PII ;
const int N = 2e5 + 10 , INF = 0x3f3f3f3f , mod = 1e9 + 7;
int e[N] , ne[N] , w[N] , h[N] , idx , n , m , vis[N] ;
void add(int a , int b , int c) {
  e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx ++ ;
}
ll dp[N] ;
void dfs(int u , int f){
  for(int i = h[u] ; ~i ; i = ne[i]) {
    int v = e[i] ;
    if(v == f) continue ;
    dfs(v , u) ;
    if(dp[v] || vis[v])
      dp[u] += dp[v] + w[i] ;
  }
  return ;
}
void dfs1(int u , int f , ll sum) {
  dp[u] += sum ;
  for(int i = h[u] ; ~i ; i = ne[i]) {
    int v = e[i] ;
    if(v == f) continue ;
    ll x = dp[u] - dp[v] - w[i] ;
    ll res = x == 0 ? (vis[u] ? w[i] : 0 ) : x + w[i] ;
    if(dp[v] || vis[v])
      dfs1(v , u , res) ;
  }
}
int work()
{
  scanf("%d%d" , &n , &m) ;
  memset(h , -1 , sizeof h) ;
  for(int i = 1; i < n ;i ++ ) {
    int a , b , c ;
    scanf("%d%d%d" , &a , &b , &c) ;
    add(a , b , c) , add(b , a , c) ;
  }
  int res , ans = 0 ;
  for(int i = 1; i <= m ;i ++ ) {
    int x ;
    scanf("%d" , &x) ;
    res = x ;
    vis[x] = 1;
  }
  if(m == 1) {
    return 0 * puts("1") ;
  }
  dfs(1 , 0) ;
  dfs1(1 , 0 , 0) ;
  for(int i = 1; i <= n ;i ++ )
   if(dp[i] == dp[res]) ans ++ ;
  cout << ans << "\n" ;
  return 0 ;
}
int main()
{
  work() ;
  return 0 ;
}