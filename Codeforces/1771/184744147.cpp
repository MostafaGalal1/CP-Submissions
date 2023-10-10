#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll n;
        cin >> n;
        bool done = false;

        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll cnt1 = 0 , cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[0]){
                cnt1++;
            }
            if (a[n-1-i] == a[n-1]){
                cnt2++;
            }
        }

        if (cnt1 <= n/2 || cnt2 <= n/2){
            cout <<  cnt1 * cnt2 * 2 << endl;
        } else
            cout << n * (n-1) << endl;
    }
}