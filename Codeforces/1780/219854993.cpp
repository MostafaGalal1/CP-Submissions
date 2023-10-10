#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long ll;

ll N = 2e5 + 5, inf = LONG_MAX, mod = 1e9 + 7;
void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();
    ll t;
    cin >> t;
//    t = 1;

    while (t --> 0) {
        ll st, n, nn;
        cin >> st;
        n = st;

        ll cur = 0;
        bitset<30> b;
        for (int i = 0; i < st; ++i) {
            cout << "- " << (1ll << cur) << '\n';
            cout.flush();
            cin >> nn;
            b[cur + nn - n + 1].flip();
            cur += nn - n + 2;
            n = nn;
        }

        cout << "! " << b.to_ullong() << endl;
        cout.flush();
    }
    return 0;
}