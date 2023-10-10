#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        ll sa = 0, sb = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i])
                sa++;
            else if (a[i] < b[i])
                sb++;
        }

        if (sa > sb)
            cout << "RED";
        else if (sb > sa)
            cout << "BLUE";
        else
            cout << "EQUAL";

        cout << endl;
    }

    return 0;
}