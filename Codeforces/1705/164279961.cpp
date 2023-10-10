#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
   int t;
   cin >> t;

    while (t --> 0) {
        int n, x;
        bool done = false;
        cin >> n >> x;
        vector<int> a(2*n);

        for (int i = 0; i < 2*n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            if(a[n+i] - a[i] < x){
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";
        cout << endl;
    }
    return 0;
}