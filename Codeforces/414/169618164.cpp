#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, k, num;
    cin >> n >> k;
    
    num = n/2 - 1;

    if (n == 1 && k == 0)
        cout << 1;
    else {
        if (k - num <= 0 || num < 0) {
            cout << -1;
        } else {
            int i, cnt = 0;
            cout << k - num << ' ' << 2 * (k - num) << ' ';
            for (i = 1; i <= 10e9 && cnt < n / 2 - 1; i += 2) {
                if (!(i == k - num || i == 2 * (k - num) || i + 1 == k - num || i + 1 == 2 * (k - num))) {
                    cout << i << ' ' << i + 1 << ' ';
                    cnt++;
                }
            }
            if (n % 2) {
                while (i == k - num || i == 2 * (k - num) || i + 1 == k - num || i + 1 == 2 * (k - num))
                    i++;
                cout << i;
            }
        }
    }

    cout << endl;
}
