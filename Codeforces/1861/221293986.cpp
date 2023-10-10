#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5+5, inf = LONG_MAX, mod = 1e9+7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main() {
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        string firs, fdg;
        cin >> firs >> fdg;

        bool ok = false;
        ll n = (ll)firs.size();
        for (int i = 0; i < n-1; ++i) {
            if (firs[i] == fdg[i] && firs[i] == '0' && firs[i+1] == fdg[i+1] && firs[i+1] == '1') {
                ok =true;
                break;
            }
        }

        if (!ok)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}