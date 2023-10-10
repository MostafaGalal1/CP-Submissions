#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        int n, count = 0;
        cin >> n;
        char arr[n][n];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n/2; i++){
            for (int j = i; j < n-1-i; j++){
                int zeros = 0, ones = 0;
                if (arr[i][j] == '0')
                    zeros++;
                else
                    ones++;

                if (arr[j][n-1-i] == '0')
                    zeros++;
                else
                    ones++;

                if (arr[n-1-i][n-1-j] == '0')
                    zeros++;
                else
                    ones++;

                if (arr[n-1-j][i] == '0')
                    zeros++;
                else
                    ones++;

                count += min(zeros, ones);
            }
        }

        cout << count << endl;
    }
    return 0;
}