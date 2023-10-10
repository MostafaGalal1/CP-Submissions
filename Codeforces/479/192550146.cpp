#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n;
    cin >> n;

    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i].second <= a[i+1].second && a[i+1].second >= res){
            res = a[i+1].second;
        } else {
            res = a[i+1].first;
        }
    }

    if (n == 1)
        cout << a[0].second << endl;
    else 
        cout << res << endl;

    return 0;
}