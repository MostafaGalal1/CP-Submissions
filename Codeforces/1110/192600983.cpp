#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e5+7, mod = 1e9+7;
const long double PI = 3.14159265358979323846264;

void fast() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

int main()
{
    ll b, k;
    cin >> b >> k;
    vector<ll> a(k);

    for (int i = 0; i < k; i++){
        cin >> a[i];
    }

    if(b%2 == 0){
        if (a[k-1]%2)
            cout << "odd";
        else
            cout << "even";
    } else {
        ll o = 0;
        for (int i = 0; i < k; i++){
            if (a[i]%2)
                o++;
        }
        if (o%2)
            cout << "odd";
        else
            cout << "even";
    }
    cout << endl;
    return 0;
}