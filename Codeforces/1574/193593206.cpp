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

    while (t --> 0){
        ll a, b, c, m;
        cin >> a >> b >> c >> m;

        if (a + b + c - 3 >= m && a <= b + c + 1 + m && b <= a + c + 1 + m && c <= a + b + 1 + m)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}