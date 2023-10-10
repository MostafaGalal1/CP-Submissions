#include <bits/stdc++.h>
#define loop(n)      for (int i=0;i<n ;i++)
#define endl     '\n'
#define ll     long long
using namespace std;

void init()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main()
{
    init() ;
    priority_queue<int> pq;
    ll n ,num,c=0;
    string s ;
    vector <string> v ;
    cin>> n ;
    while(n--)
    {
        cin>>s ;
        if (s=="insert")
        {
            cin>>num;
            v.push_back(s+" "+to_string(num)) ;
            pq.push(-num) ;
        }
        else if (s=="removeMin")
        {
            if(pq.empty())
                v.push_back("insert "+to_string(0));
            else
                pq.pop();
            v.push_back("removeMin");
        }
        else if (s=="getMin")
        {

            int x;
            cin>>x;
            while(!pq.empty() && -pq.top()<x)
            {
                v.push_back("removeMin");
                pq.pop();
            }
            if(pq.empty() || (!pq.empty() && -pq.top()>x))
            {
                pq.push(-x);
                v.push_back("insert "+to_string(x));
            }
            v.push_back("getMin "+to_string(x));
        }
    }

    cout<<v.size() <<endl ;
    for(auto i:v)
    {
        cout<<i<<endl ;
    }
    return 0 ;
}
