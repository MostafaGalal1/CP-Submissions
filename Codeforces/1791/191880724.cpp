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

    while (t --> 0) {
        ll n;
        string s;
        bool done = false;
        cin >> n >> s;

        ll cnt = n;

        for (int i = 0; i < n/2; ++i) {
            if (s[i] == s[n-1-i]){
                break;
            } else
                cnt -= 2;
        }

        cout << cnt << endl;
    }
    return 0;
}