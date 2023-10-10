#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll t;
    cin >> t;

    while (t-->0) {
        ll n;
        bool l = true, done = false;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n == 1){
            cout << "YES" << endl;
            continue;
        }

        for (int i = 1; i < n; ++i) {
            if (a[i-1] > a[i]) {
                l = true;
            } else if (a[i-1] < a[i]) {
                if (l){
                    if (done) {
                        done = false;
                        l = false;
                        break;
                    }
                    done = true;
                }
                l = false;
            }
        }

        if (l){
            if (done)
                done = false;
            else
                done = true;
        }

        if (done)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}