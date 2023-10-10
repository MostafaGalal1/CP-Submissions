#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t --> 0){
        int n, k;
        cin >> n >> k;

        if (k > n){
            cout << "NO" << endl;
            continue;
        }

        if (n%2 == 1 && k%2 == 0)
            cout << "NO";
        else if (n%2 == 1 && k%2 == 1){
            cout << "YES" << endl;
            cout <<  n-(k-1) << " ";
            for (int j = 0; j < k-1;j++){
                cout << 1 << " ";
            }
        } else if (n%2 == 0 && k%2 == 0){
            cout << "YES" << endl;
            cout <<  n-(k-1) << " ";
            for (int j = 0; j < k-1;j++){
                cout << 1 << " ";
            }
        } else if (n%2 == 0 && k%2 == 1){
            if (n-(k-1)*2 >= 2) {
                cout << "YES" << endl;
                cout << n - (k - 1) * 2 << " ";
                for (int j = 0; j < k - 1; j++) {
                    cout << 2 << " ";
                }
            } else {
                cout << "NO";
            }
        }
        cout << endl;

        }

    return 0;
}