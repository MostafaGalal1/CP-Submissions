#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    fast();

    ll n, nu;
    cin >> n;
    set<ll> a;

    for (int i = 0; i < n; ++i) {
        cin >> nu;
        a.insert(nu);
    }

    if ((ll)a.size() < 3)
        cout << "YES";
    else if ((ll)a.size() == 3) {
        if (*a.begin() + *prev(a.end()) == 2 * *prev(prev(a.end())))
            cout << "YES";
        else
            cout << "NO";
    } else
        cout << "NO";
    cout << endl;
    return 0;
}