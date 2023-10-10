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
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll mn = 1, mx = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[0])
            mn++;
    }

    for (int i = n-2; i >= 0; --i) {
        if (a[i] == a[n-1])
            mx++;
    }

    cout << a[n-1] - a[0] << ' ';
    if (mx + mn > n)
        cout << n * (n-1) / 2;
    else
        cout << mx * mn;
    cout << endl;

    return 0;
}