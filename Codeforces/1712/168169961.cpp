#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef long double ld;

const ll N = 1e6+10, M = 110, inf = 1e9+7,mod = 1e9+7,sqr = 450;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n, sum = 0;
        cin >> n;

        set<ll> s;
        vector<ll> v(n);
        map<ll,ll> mapp;

        for(ll i = 0; i < n; i++){
            cin >> v[i];
            mapp[v[i]]++;
            s.insert(v[i]);
        }
        
        ll j = n - 1;
        while(j >= 0){
            ll cnt = 1;
            for(ll i = 0; i < mapp[v[j]] - 1; i++){
                if(v[j-i-1] != v[j])
                    cnt = 0;
            }
            if(j != n-1 && v[j] > v[j+1]){
                break;
            }
            if(cnt){
                s.erase(v[j]);
                j -= mapp[v[j]];

            }
            else {
                break;
            }
        }

        for(auto it : s){
            sum++;
        }
        cout<< sum <<endl;
    }

    return 0;
}