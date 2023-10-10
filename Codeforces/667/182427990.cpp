#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    long double d, h, v, e;
    cin >> d >> h >> v >> e;
    e = d * d / 4.0 * PI * e;

    if (e - v > 0){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl << setprecision(16) << h*(d*d/4.0*PI)/(v-e) << endl;

    return 0;
}