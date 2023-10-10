#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t--) {
        ll n;
        cin >> n;

        bool done = false;
        for (int i = 2; i < 1000; ++i) {
            ll nu = n, cnt = 0;
            while (nu > 0){
                nu -= pow(i, cnt++);
            }
            if (nu == 0 && cnt > 2) {
                done = true;
                break;
            }
        }

        if (done)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}