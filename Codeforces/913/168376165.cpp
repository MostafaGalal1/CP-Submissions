#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define oo INFINITY
#define lp(i,n) for (int i = 0; i < n; i++)


// long looooooooooooooooooong
void solve(ll kkkk, ll tttt)
{
    ll n, l; cin >> n >> l;
    vector<ll> arr(35); for (ll i = 0; i < n; i++) cin >> arr[i];
    for (ll i = 1; i < n; i++)
        arr[i] = min(arr[i - 1] * 2, arr[i]);
    for (ll i = n; i < 31; i++)
        arr[i] = arr[i - 1] * 2;

    ll ans = 0;

    for (ll i = 0; i < 31; i++)
    {
        ll liters = pow(2, i);
        if (l & liters)
            ans += arr[i];
        else
            ans = min(ans, arr[i]);
    }
    for (ll i = n; i < 31; i++)
        arr[i] = arr[i - 1] * 2;
//
//    for (ll i = 0; i < 31; i++)
//    {
//        ll liters = pow(2, i);
//        if (liters > l)
//            ans = min(ans, arr[i]);
//    }
    cout << ans << endl;
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
