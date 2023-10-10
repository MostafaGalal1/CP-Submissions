#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n;
        cin >> n;

        ll mx = 0;
        multiset<ll> a, b;

        ll num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            a.insert(num);
        }

        for (int i = 0; i <= 100; ++i) {
            b = a;

            int j;
            bool done = false;;

            for (j = 1; j <= i; ++j) {
                auto i1 = lower_bound(b.begin(), b.end(), i - j + 2);
                if (i1 == b.begin()){
                    done = true;
                    break;
                }
                b.erase(prev(i1));
                num = *b.begin();
                b.insert(num + i - j + 1);
                b.erase(b.begin());
            }

            if (!done)
                mx = max(mx, (ll)(j-1));
        }

        cout << mx << endl;
    }
    return 0;
}