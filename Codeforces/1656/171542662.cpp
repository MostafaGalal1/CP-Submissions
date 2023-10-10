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
        cin >> n;

        if (n%2)
            cout << 2;
        else {
            if (log2(n) == floor(log2(n)))
                cout << -1;
            else if (n%6 == 0)
                cout << 3;
            else if (n%4 == 2)
                cout << 4;
            else if (n%4 == 0) {
                if (n%10 == 0)
                    cout << 5;
                else {
                    ll x = n;
                    while(x % 2 == 0) x /= 2;
                    if(x <= 2e9 && (x*(x+1))/2 <= n)
                        cout << x;
                    else
                        cout << 2*(n/x);
                }
            }
        }
        cout << endl;
    }

    return 0;
}
