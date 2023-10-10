#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

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

    long double sum = 0;
    for (int i = 0; i < n-1; ++i) {
        sum += a[i];
    }

    if (sum > a[n-1]){
        cout << 0;
    } else {
        cout << (ll)(a[n-1] - sum + 1);
    }
    cout << endl;

    return 0;
}