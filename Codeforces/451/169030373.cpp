#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    bool fixed = false, done = false;
    ll n, bre1 = 0, bre2 = 0;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    for (int i = 0; i < n-1; ++i) {
        if (bre1 && !fixed && arr[i] < arr[i+1]) {
            bre2 = i+1;
            fixed = true;
        } else if (!bre1 && arr[i] > arr[i+1]){
            bre1 = i+1;
        }
    }
    if (!bre1 && !bre2)
        bre2 = 1;
    else if (!bre2)
        bre2 = n;
    if (!bre1)
        bre1 = 1;

    for (ll i = bre2-1; i < n-1; ++i) {
        if (arr[i] > arr[i+1]){
            done = true;
            break;
        }
    }

    if (!done && ((bre2 > n-1) || (arr[bre2] > arr[bre1-1])) && (bre1 - 2 < 0 || arr[bre1-2] < arr[bre2 - 1])) {
        cout << "yes" << endl;
        cout << bre1 << ' ' << bre2;
    } else
        cout << "no";

    cout << endl;
    return  0;
}
