#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n1, n2, num, e1 = 0, o1 = 0, e2 = 0, o2 = 0;
        cin >> n1;

        for (int i = 0; i < n1; ++i) {
            cin >> num;
            if (num%2)
                e1++;
            else
                o1++;
        }

        cin >> n2;

        for (int i = 0; i < n2; ++i) {
            cin >> num;
            if (num%2)
                e2++;
            else
                o2++;
        }

        cout << e1 * e2 + o1 * o2 << endl;
    }

    return  0;
}
