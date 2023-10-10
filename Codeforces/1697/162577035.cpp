#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int q = 0;
    cin >> q;
    int arr[n];

    for (int j = 0; j < n; j++) {
        cin >> arr[j];
    }

    sort(arr, arr + n);

    long long pre[n];

    long long sum = 0;
    for (int j = 0; j < n; j++) {
        sum += arr[j];
        pre[j] = sum;
    }

    for (int i = 0; i < q; i++) {
        int x = 0;
        cin >> x;
        int y = 0;
        cin >> y;

        if (n-1-x < 0)
            cout << pre[n - 1 - x + y] << endl;
        else
            cout << pre[n - 1 - x + y] - pre[n - 1 - x] << endl;
    }

    return 0;
}
