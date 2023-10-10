#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0){
        bool done = false;
        ll n, cnt = 0;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool chan = false;
        while (!chan) {
            chan = true;
            for (int i = 0; i < n-1; ++i) {
                while(a[i] >= a[i + 1] && a[i]) {
                    a[i] /= 2, cnt++, chan = false;
                }
            }
        }

        for (int i = 0; i < n-1; ++i) {
            if (a[i] == a[i+1]) {
                done = true;
                break;
            }
        }

        if (!done)
            cout << cnt;
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}