#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        int min = INT_MAX;
        int count = 0;

        for (int j = 0; j < n; j++){
            cin >> arr[j];
            if (min > arr[j])
                min = arr[j];
        }

        for (int j = 0; j < n; j++){
            count += arr[j] - min;
        }

        cout << count << endl;
    }
}
