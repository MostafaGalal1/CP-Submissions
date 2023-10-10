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
        ll n;
        bool zero = false, one = false, cons = false;
        cin >> n;
        vector<ll> a(n+1);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a[n] = LONG_LONG_MAX;

        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            if (!zero && a[i] == 0)
                zero = true;
            else if (!one && a[i] == 1)
                one = true;
            if (!cons && (a[i+1] == a[i] + 1))
                cons = true;
        }
        
        if ((zero && one) || (one && cons))
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }

    return 0;
}
