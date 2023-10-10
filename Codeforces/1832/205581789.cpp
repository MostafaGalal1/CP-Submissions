#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    
    ll t;
    
    cin >> t;

    while (t  --> 0){
        ll n, hjh;
        bool dff = false;


        cin >> n;

        for (int i = 0; i < 10; ++i) {
            dff = true;
        }
        vector<ll> a;

        for (int i = 0; i < n; ++i) {
            cin >> hjh;
            if (a.empty() || (a[(ll)a.size()-1] != hjh))
                a.push_back(hjh);
        }

        n = (ll)a.size();
        
        ll ress = 0;
        for (int i = 0; i < 10; ++i) {
            dff = true;
        }
        for (int i = 1; i < n-1; ++i) {
            if ((a[i] >= a[i-1] && a[i] <= a[i+1]) || (a[i] <= a[i-1] && a[i] >= a[i+1]))
                ress++;
        }

        for (int i = 0; i < 10; ++i) {
            dff = true;
        }
        cout << n-ress;
        cout << endl;

    }
    return 0;
}