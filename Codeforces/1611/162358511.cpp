#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int index = 1;
        int max = 0;
        int n = 0;
        cin >> n;
        int arr[n];
        int res[n];

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (arr[j] > max) {
                max = arr[j];
                index = j;
            }
        }

        if (index != 0 && index != n - 1){
            cout << -1 << endl;
            continue;
        }

        res[n/2] = arr[index];
        int num = (index==0)? n-1: n-2;
        for (int j = 0; j < n-1; j++){
            res[(n/2 + 1 + j)%n] = arr[num-j];
        }

        for (int j = 0; j < n; j++){
            cout << res[j] << " ";
        }

        cout << endl;
    }
    return 0;
}
