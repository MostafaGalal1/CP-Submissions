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
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> odd;

        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i]%2) {
                ll cnt = 0;
                while (a[i]%2){
                    a[i] = a[i]/2;
                    cnt++;
                }
                odd.push_back(cnt);
            } else {
                ll cnt = 0;
                while (a[i]%2 == 0){
                    a[i] = a[i]/2;
                    cnt++;
                }
                odd.push_back(cnt);
            }
        }

        if (sum%2 == 0){
            cout << 0;
        } else {
            sort(odd.begin(), odd.end());
            cout << odd[0];
        }

        cout << endl;
    }
    return 0;
}