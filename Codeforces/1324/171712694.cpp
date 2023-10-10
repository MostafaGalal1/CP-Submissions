#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

        ll n, num, cnt = 0;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> num;
            a[i] -= num;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(a.begin(), a.end(), -a[i]+1);
            cnt += n - (it - a.begin());
            if (a[i] > 0)
                cnt--;
        }

        cout << cnt/2 << endl;

    return 0;
}
