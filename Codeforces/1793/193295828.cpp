#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main() {
    fast();

    ll t;
    cin >> t;

    while (t--> 0){
        ll a, b;
        cin >> a >> b;
        int n = 2 + (a - b - 1) * 2;
        cout << n << endl;
        for (int i = a; i >= b; i--)
            cout << i << " ";
        for (int i = b + 1; i < a; i++)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
