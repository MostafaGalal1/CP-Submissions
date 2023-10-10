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
        ll m, cnt = 0;
        cin >> m;
        bool done = false;

        vector<ll> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < (ll)log2(m); ++i) {
            ll curpow = (ll)pow(2, i+1);
            for (int j = 0; j < m; j += curpow) {
                ll mn = LONG_LONG_MAX, mx = 0;
                for (int k = 0; k < curpow; ++k) {
                    mn = min(mn, a[j+k]);
                    mx = max(mx, a[j+k]);
                }
                if (j+curpow/2 < m && a[j+curpow/2-1] > a[j+curpow/2]){
                    cnt++;
                }
                if (mx - mn >= curpow){
                    cout << -1;
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }

        if (!done)
            cout << cnt;
        cout << endl;
    }
    return 0;
}