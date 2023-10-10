#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main()
{
    fast();

    ll t, tt;
    cin >> t;
    tt = t;

    while (t --> 0) {
        ll a, b;
        cin >> a >> b;

        if (a == b)
            cout << 0;
        else if (a > b) {
            if ((a-b)%2)
                cout << 2;
            else
                cout << 1;
        } else {
            if ((b-a)%2)
                cout << 1;
            else
                cout << 2;
        }
        cout << endl;
    }

    return 0;
}
