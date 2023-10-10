#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v;

    for(int i = 1; i <= (ll)sqrt(n); ++i){
        if(n%i==0)
            v.push_back(i);
    }

    ll sz = (ll)v.size();
    for (int i = sz - 1; i >= 0; --i) {
        if (n/v[i] != v[i])
            v.push_back(n/v[i]);
    }

    if (k > v.size())
        cout << -1;
    else {
        cout << v[k-1];
    }
    cout << endl;

    return 0;
}