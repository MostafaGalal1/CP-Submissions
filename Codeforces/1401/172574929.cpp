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
    while (t --> 0){
        ll n, k;
        cin >> n >> k;

        if (k <= n){
            if (n%2 == k%2)
                cout << 0;
            else
                cout << 1;
        } else {
            cout << k - n;
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}