#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n = 0;
        cin >> n;
        int num = 0;
        int count = 0;
        int arr[n];
 
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }
        
        sort(arr, arr + n);
        
        for (int j = 0 ; j < n-1; j++){
            if (arr[j] == arr[j+1])
                count++;
        }
        
        if (count%2 == 1)
            count++;
        
        cout << n - count << endl;
    }
    return 0;
}