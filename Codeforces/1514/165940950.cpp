#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t-- > 0){
        bool done = false;
        int n, num;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (!done && num != pow((int)sqrt(num), 2)){
                cout << "YES";
                done = true;
            }
        }

        if (!done)
            cout << "NO";
        cout << endl;
    }

    return 0;
}