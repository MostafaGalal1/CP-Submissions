#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {

    fast();
    
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        bool onee = true;
        cin >> n;
        vector<ll> a(n);

        cin >> a[0];
        if (a[0] != 1)
            onee = false;
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 1)
                onee = false;
            a[i] += a[i - 1];
        }

        if (onee){
            cout << 1 << endl;
            continue;
        }

        ll mx, mn = n, pos;
        for (int i = 0; i < n-1; ++i) {
            if (a[n-1] % a[i] == 0 && a[i] != 1) {
                pos = a[i];
                bool terminate = false;
                ll cur = i;
                mx = i+1;
                for (int j = i + 1; j < n; ++j) {
                    if (a[j]%a[i] == 0) {
                        if (a[j] - pos == a[i]) {
                            mx = max(mx, j - cur), cur = j;
                            pos = a[j];
                        } else {
                            terminate = true;
                            break;
                        }
                    }
                }
                if (!terminate)
                    mn = min(mn, mx);
            }
        }

        cout << mn << endl;
    }
    return 0;
}