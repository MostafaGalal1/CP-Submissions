#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll i;
        for (i = n-1; i >= 0; --i) {
            if (n - i > a[i])
                break;
        }

        cout << n - i - 1 << endl;
    }

    return 0;
}
