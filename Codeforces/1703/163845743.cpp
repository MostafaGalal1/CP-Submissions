#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++){
            int len, count = 0;
            string s;
            cin >> len;
            cin >> s;
            for (int j = 0; j < len; ++j) {
                if (s[j] == 'D')
                    count++;
                else
                    count--;
            }
            arr[i] += count < 0? count+10:count;
            arr[i] %= 10;
        }

        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}