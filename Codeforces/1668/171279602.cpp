#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t --> 0){
        ll n, m, tot = 0;
        cin >> n >> m;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        tot += a[0] * 2 + 1;
        for (int i = 1; i < n-1; ++i) {
            tot += a[i] + 1;
        }
        tot += 1;

        if (tot <= m)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}