#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t --> 0){
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        ll num = min(k * (b+1) - 1, s);
        if (s - num <= (k-1) * (n-1) && k*b <= s) {
            cout << num << ' ';
            s -= num;
            for (int i = 0; i < n-1; ++i) {
                if (s >= k-1){
                    cout << k-1 << ' ';
                    s -= k-1;
                } else {
                    if (s > 0) {
                        cout << s << ' ';
                        s = 0;
                    } else
                        cout << 0 << ' ';
                }
            }
        } else
            cout << -1;
        cout << endl;
    }
    return  0;
}
