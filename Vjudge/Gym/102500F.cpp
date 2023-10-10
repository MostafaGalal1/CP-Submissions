
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <deque>
#include <bitset>
//#include <unordered_set>
//#include <unordered_map>
//#include <bits/stdc++.h>
//#include <xfunctional>
#define ll              long long
#define PII             pair<int, int>
#define rep(i,a,b)      for(int  i=a;i<=b;i++)
#define dec(i,a,b)      for(int  i=a;i>=b;i--)
#define pb              push_back
#define mk              make_pair
using namespace std;
int dir[4][2] = { { 0,1 } ,{ 0,-1 },{ 1,0 },{ -1,0 } };
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979;
const int mod = 998244353;
const int N = 2e5+5;
//if(x<0 || x>=r || y<0 || y>=c)

inline ll read()
{
    ll x = 0; bool f = true; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = false; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? x : -x;
}
ll gcd(ll m, ll n)
{
    return n == 0 ? m : gcd(n, m % n);
}
ll lcm(ll m, ll n)
{
    return m*n / gcd(m, n);
}

int f[200010];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
bool add(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
        return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        int j, k;
        scanf("%d", &j);
        while (j--) {
            scanf("%d", &k);
            m[k].push_back(i);
        }
    }
    vector<pair<PII, int>> ans;
    for (auto i : m) {
        for (int j = 1; j < i.second.size(); j++)
            if (add(i.second[j - 1], i.second[j]))
                ans.push_back({ { i.second[j - 1], i.second[j] }, i.first });
    }
    if (ans.size() != n - 1)
        printf("impossible\n");
    else
        for (auto i : ans)
            printf("%d %d %d\n", i.first.first, i.first.second, i.second);
}