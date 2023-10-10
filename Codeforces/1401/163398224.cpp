#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        bool done = false;
        int n, min = INT_MAX;
        cin >> n;
        int arr[n], arg[n];

        for (int i = 0; i < n; i++){
            cin >> arr[i];
            arg[i] = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }

        sort(arr,arr + n);

        for (int i = 0; i < n; i++) {
            if (!(arg[i] == arr[i] || arg[i] % min == 0)){
                cout << "NO";
                done = true;
                break;
            }
        }

        if(!done)
            cout << "YES";
        cout << endl;
    }
    return 0;
}