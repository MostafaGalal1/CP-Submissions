#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while(t --> 0) {
        double ang, n = 3;
        cin >> ang;

        while (ang > (n-2)/n * 180 || fmod(ang, (1 / n * 180)) > 1e-17)
            n++;

        cout << (ll) n << endl;
    }
    return 0;
}
