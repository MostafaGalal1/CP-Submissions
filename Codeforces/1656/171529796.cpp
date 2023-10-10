#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();


    ll t;
    cin >> t;

    while (t --> 0){
        ll n, mn = LONG_LONG_MAX, mx = 0, mxi, mni, num;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (mx < num)
                mx = num, mxi = i+1;
            if (mn > num)
                mn = num, mni = i+1;
        }

        cout << mni << ' ' << mxi << endl;
    }

    return 0;
}
