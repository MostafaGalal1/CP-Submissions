#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll t;
    cin >> t;

    while (t --> 0){
        bool done = false;
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n-1; ++i) {
            if (a[i] >= a[i+1])
                m += min(a[i] - a[i+1] + k, a[i]);
            else {
                if (a[i] + m + k >= a[i+1]) {
                    if (a[i + 1] - a[i] <= k)
                        m += min(k - (a[i + 1] - a[i]), a[i]);
                    else
                        m -= a[i + 1] - a[i] - k;
                } else {
                    done = true;
                    break;
                }
            }
        }

        if (done)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }

    return 0;
}
