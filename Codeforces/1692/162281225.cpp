#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int r = 0;
        int c = 0;
        char arr[8][8];
        
        cin.ignore();
        for (int j = 0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                cin >> arr[j][k];
            }
        }
        
        for (int j = 1; j < 7; j++){
            for (int k = 1; k < 7; k++){
                if (arr[j][k] == '#' && arr[j-1][k-1] == '#' && arr[j-1][k+1] == '#' && arr[j+1][k-1] == '#' && arr[j+1][k+1] == '#'){
                    r = j;
                    c = k;
                }
            }
        }
        
        cout << (r+1) << " " << (c+1) << endl;
    }
    return 0;
}