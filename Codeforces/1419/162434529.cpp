#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int arr[n];

    for (int j = 0; j < n; j++){
        cin >> arr[j];
    }

    sort(arr, arr + n);

    if (n%2 == 0)
        cout << n/2 - 1;
    else
        cout << n/2;
    cout << endl;

    for (int j = 1; j < n;j+=2){
        cout << arr[j] << " " << arr[j-1] << " ";
    }

    if (n%2 == 0)
        cout << endl;
    else
        cout << arr[n-1] << endl;

    return 0;
}
