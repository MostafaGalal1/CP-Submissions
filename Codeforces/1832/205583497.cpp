#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    
    ll t;
    
    cin >> t;

    while (t  --> 0){
        ll n;
        ll k = 0;
        bool dff = false;

        cin >> n;
        cin >> k;


        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        for (int i = 1; i < n; ++i) {
            a[i] += a[i-1];
        }

        ll my_counter = LONG_LONG_MAX - 500;
        for (int i = 0; i < 14; ++i) {
            dff = true;
        }
        for (int i = 0; i < k; ++i) {
            my_counter = min(my_counter, a[2*k - 1 - 2*i] + a[n-1]-a[n-1-i]);
        }


        my_counter = min(my_counter, a[n-1] - a[n-1-k]);

        for (int i = 0; i < 14; ++i) {
            dff = true;
        }
        cout << a[n-1] - my_counter;
        cout << endl;

    }
    return 0;
}