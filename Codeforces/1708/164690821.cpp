#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t --> 0){
        int n;
        bool done = false;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 1; i < n; ++i) {
            if (arr[i]%arr[0] != 0){
                cout << "NO";
                done = true;
                break;
            }
        }

        if (!done)
            cout << "YES";

        cout << endl;
    }
}