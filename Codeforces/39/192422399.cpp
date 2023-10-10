#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();
    ll n;
    cin >> n;
    char s[33];

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            itoa(i * j, s, n);
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}