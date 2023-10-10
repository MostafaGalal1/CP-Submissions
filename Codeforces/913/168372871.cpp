#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define oo INFINITY
#define lp(i,n) for (int i = 0; i < n; i++)


// long looooooooooooooooooong
void solve(ll kkkk, ll tttt)
{
    ll n, m; cin >> n >> m;

    if (n > 50)
    {
        cout << m << endl;
        return;
    }
    n = pow(2, n);
    m %= n;
    cout << m << endl;
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
