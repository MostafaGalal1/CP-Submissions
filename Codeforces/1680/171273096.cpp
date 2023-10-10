#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;

    while (t --> 0) {
        bool done = false;
        int n, m;
        cin >> n >> m;
        char a[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        int fu = -1, fl = -1;
        for (int i = 0; i < n && !done; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'R' && fu == -1){
                    fu = j;
                } else if (a[i][j] == 'R' && j < fu){
                    cout << "NO";
                    done = true;
                    break;
                }
            }
        }

        for (int i = 0; i < m && !done; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j][i] == 'R' && fl == -1){
                    fl = i;
                } else if (a[j][i] == 'R' && i < fl){
                    cout << "NO";
                    done = true;
                    break;
                }
            }
        }

        if (!done)
            cout << "YES";
        cout << endl;
    }
    return 0;
}