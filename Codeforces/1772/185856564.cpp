#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll k, n;
        cin >> k >> n;
        vector<ll> a;


        ll st = 1;
        for(int i=1;i<=k;++i)
        {
            if (st > n)
                break;
            else{
                a.push_back(st);
                st += i;
            }
        }

        ll cnt = (ll)a.size();
        while (n - a[cnt-1] + 1 <= k - cnt)
            cnt--;

        for (int i = 0; i < cnt; ++i) {
            cout << a[i] << ' ';
        }

        for (int i = 1; i <= k - cnt; ++i) {
            cout << a[cnt-1] + i << ' ';
        }

        cout << endl;
    }
    return 0;
}