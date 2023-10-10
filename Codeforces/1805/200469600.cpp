#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 105, mod = 1e9 + 7;
const long double PI = 3.14159265358979323846264;
const int siz = 3e5 + 10, inf = INT_MAX;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        string s;
        ll n;
        cin >> n;
        cin >> s;
        bool done = false;
        ll ind = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] <= s[ind]){
                ind = i;
            }
        }

        cout << s[ind];
        for (int i = 0; i < n; ++i) {
            if (i != ind)
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}