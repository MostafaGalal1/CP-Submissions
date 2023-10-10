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
        bool done = false;
        ll a[2][2];

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> a[i][j];
            }
        }

        if ((a[0][0] < a[0][1] && a[0][0] < a[1][0]) && (a[1][1] > a[0][1] && a[1][1] > a[1][0]))
            cout << "yes";
        else if ((a[0][1] < a[0][0] && a[0][1] < a[1][1]) && (a[1][0] > a[0][0] && a[1][0] > a[1][1]))
            cout << "yes";
        else if ((a[1][1] < a[0][1] && a[1][1] < a[1][0]) && (a[0][0] > a[0][1] && a[0][0] > a[1][0]))
            cout << "yes";
        else if ((a[1][0] < a[0][0] && a[1][0] < a[1][1]) && (a[0][1] > a[0][0] && a[0][1] > a[1][1]))
            cout << "yes";
        else
            cout << "no";

        cout << endl;
    }
    return 0;
}