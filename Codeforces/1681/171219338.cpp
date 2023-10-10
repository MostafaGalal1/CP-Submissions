#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t --> 0){
        int n, m;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cin >> m;
        vector<int> b(m);

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a[n-1] > b[m-1])
            cout << "Alice\nAlice" << endl;
        else if (a[n-1] < b[m-1])
            cout << "Bob\nBob" << endl;
        else
            cout << "Alice\nBob" << endl;
    }

    return 0;
}