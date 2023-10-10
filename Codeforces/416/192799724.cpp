#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e4+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll n, nu;
    char ans;
    cin >> n;
    string op;

    ll mn = -2*1e9, mx = 2*1e9;

    for (int i = 0; i < n; ++i) {
        cin >> op >> nu >> ans;
        if ((op == ">=" && ans == 'Y') || (op == "<" && ans == 'N')){
            mn = max(mn, nu);
        } else if ((op == ">" && ans == 'Y') || (op == "<=" && ans == 'N')) {
            mn = max(mn, nu + 1);
        } else if ((op == "<=" && ans == 'Y') || (op == ">" && ans == 'N')){
            mx = min(mx, nu);
        } else if ((op == "<" && ans == 'Y') || (op == ">=" && ans == 'N')) {
            mx = min(mx, nu - 1);
        }
    }

    if (mx >= mn)
        cout << (mn + mx)/2;
    else
        cout << "Impossible";
    cout << endl;

    return 0;
}