#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll t = 1;

    while (t --> 0) {
        ll k, n;
        bool done = false;
        cin >> k >> n;

        ll cnt = 0;
        while (n%k == 0 && n != k){
            cnt++;
            n/=k;
        }

        if (n == k)
            done = true;

        if (!done)
            cout << "NO";
        else
            cout << "YES" << endl << cnt;
        cout << endl;
    }
    return 0;
}