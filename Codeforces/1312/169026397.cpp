#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while(t --> 0) {
        ll n, m;
        cin >> n >> m;

        cout << (max(n, m) % min(n, m)? "NO" : "YES") << endl;
    }

    return  0;
}
