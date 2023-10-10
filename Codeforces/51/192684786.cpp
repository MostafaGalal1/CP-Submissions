#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n;
    char n1, n2, n3, n4;
    char ch;

    cin >> n;
    set<ll> s;

    for (int i = 0; i < n; ++i) {
        cin >> n1 >> n2 >> n3 >> n4;
        n1 -= 48, n2 -= 48, n3 -= 48, n4 -= 48;
        ll res = n1 + n2 * 10 + n4 * 100 + n3 * 1000;
        bool done = false;
        for (int j = 0; j < 4; ++j) {
            if (s.find(res) != s.end()){
                done = true;
                break;
            }
            res = res / 1000 + (res % 1000) * 10;
        }

        if (!done)
            s.insert(res);

        if (i < n-1)
            cin >> ch >> ch;
    }

    cout << (ll)s.size() << endl;
    return 0;
}