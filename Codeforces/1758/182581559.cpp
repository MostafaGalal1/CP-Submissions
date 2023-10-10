#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while (t --> 0) {
        ll n;
        cin >> n;

        if (n%2){
            for (int i = 0; i < n; ++i) {
                cout << 1 << ' ';
            }
            cout << endl;
        } else {
            cout << 1 << ' ' << 3 << ' ';
            for (int i = 0; i < n-2; ++i) {
                cout << 2 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}