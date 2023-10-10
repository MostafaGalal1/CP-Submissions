#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t --> 0) {
        ll n, sum = 0;
        string s;
        cin >> s;
        n = (ll)s.length();

        for (int i = 0; i < n; ++i) {
            sum += (s[i] - 'a' + 1);
        }

        if (n == 1){
            cout << "Bob " << sum;
        } else {
            if (n%2)
                cout << "Alice " << max(sum - 2*(s[n-1] - 'a' + 1), sum - 2*(s[0] - 'a' + 1));
            else
                cout << "Alice " << sum;
        }

        cout << endl;
    }
    return 0;
}