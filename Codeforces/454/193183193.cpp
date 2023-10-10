#include <bits/stdc++.h>

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
    int ind = 0;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
        if (a[i+1] < a[i]){
            ind = i+1;
            break;
        }
    }

    bool done = false;
    ll cnt = 0;
    for (int i = ind; cnt < n-1; i = (i+1)%n) {
        if (a[(i+1)%n] < a[i]){
            done = true;
            break;
        }
        cnt++;
    }

    if (done)
        cout << -1;
    else
        cout << (n - ind)%n;
    cout << endl;
}
