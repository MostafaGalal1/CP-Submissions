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

    while (t --> 0) {
        ll n, num, zeros = 0, ones = 0;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (!num)
                zeros++;
            else if (num == 1)
                ones++;
        }

        cout << ones * ((ll)pow(2, zeros)) << endl;
    }

    return 0;
}