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
        ll a1, a2, b1, b2, c1, c2;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        if ((a1 == b1 && (b2 == c2 || a2 == c2)) || (a1 == c1 && (c2 == b2 || a2 == b2)) || (b1 == c1 && (b2 == a2 || c2 == a2))){
            cout << "NO";
        } else {
            cout << "YES";
        }

        cout << endl;
    }
    return 0;
}