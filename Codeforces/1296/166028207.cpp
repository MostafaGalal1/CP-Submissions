#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0){
        int n, odds = 0;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if(arr[i]%2 == 1)
                odds++;
        }

        if(odds%2 == 1 || (odds > 0 && odds < n && odds%2 == 0))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}

