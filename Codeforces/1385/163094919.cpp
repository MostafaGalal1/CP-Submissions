#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t --> 0){
        int n, index1 = 0, index2 = 0;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = n-1; i >= 0; i--){
            if (arr[i] > arr[i-1]) {
                index1 = i;
                break;
            }
        }

        for (int i = index1; i >= 0; i--){
            if (arr[i] < arr[i-1]) {
                index2 = i;
                break;
            }
        }

        cout << index2 << endl;
    }

    return 0;
}