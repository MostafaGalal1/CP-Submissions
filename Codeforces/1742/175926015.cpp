#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    ll t;
    cin >> t;

    while (t --> 0) {
        bool don = false;
        char arr[8][8];

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 8; ++i) {
            bool done = false;
            for (int j = 0; j < 8; ++j) {
                if (arr[i][j] == 'B' || arr[i][j] == '.'){
                    done = true;
                    break;
                }
            }
            if (!done){
                cout << 'R';
                don = true;
                break;
            }
        }


        if (!don)
            cout << 'B';
        cout << endl;
    }

    return 0;
}