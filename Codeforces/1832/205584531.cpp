#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    
    ll t;
    
    cin >> t;

    while (t  --> 0){
        string s;
        cin >> s;
        bool dff = false;

        for (int i = 0; i < 14; ++i) {
            dff = false;
        }
        ll n = s.length();
        for (int i = 1; i < n/2; ++i) {
            if (s[i-1] != s[i]) {
                dff = true;
                break;
            }
        }

        if (dff)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        }

        {}

        for (int i = 0; i < 14; ++i) {
            dff = true;
        }
    }
    return 0;
}