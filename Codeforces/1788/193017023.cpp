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

    while (t-->0) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll tw = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 2)
                tw++;
        }

        if (tw) {
            if (tw % 2)
                cout << -1;
            else {
                ll cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i] == 2)
                        cnt++;
                    if (cnt == tw/2){
                        cout << i+1;
                        break;
                    }
                }
            }
        } else
            cout << 1;
        cout << endl;
    }

    return 0;
}