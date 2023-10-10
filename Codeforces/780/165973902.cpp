#include<bits/stdc++.h>
using namespace std;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define F first
#define S second
#define oo 10000000
#define pb push_back
#define mpr make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define foor(i,a,b) for (int i = a; i < b; i++)
#define num_ocur_insort(vec,x) equal_range(all(vec), x) // return pair upper lower   auto r=num_ocur_insort(a,6);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }

vii adjlist;
struct bebo{
    ll first;
    ll second;
    ll third;
};
queue<bebo> q;
map<ll,bool> visited;
map<ll,bool> taken;
ll maxo=0;
mapi mp;
ll zz;
void bfs(bebo s){

    q.push(s);
    visited[s.first]=true;
    mp[1]=1;

    while(!q.empty()){
        taken.clear();
        auto xx=q.front();
        q.pop();
        ll x=xx.first;
        ll col=xx.second;
        ll grand=xx.third;

        zz=1;
        taken[col]=true;
        taken[grand]=true;
        for(auto u:adjlist[x]){
            if(visited[u])continue ;
            visited[u]=true;

            foor(i,zz,maxo+2)
            {
                if(taken[i]==true)continue;
                zz=i;
                zz++;
                taken[i]=true;
                mp[u]=i;
                q.push({u,i,col});
                break;
            }

        }
    }
}



int main()
{ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vii a(n+1);
    adjlist=a;

    foor(i,0,n-1){
        ll  x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }

    foor(i,1,n+1){
        ll cc=adjlist[i].size();
        maxo=max(maxo,cc);
    }
    cout<<maxo+1<<endl;
    bebo hh={1,1,0};
    bfs(hh);

    for(auto it : mp){
        cout<<it.second<<" ";
    }


}

		 		     		  		   		   				  	