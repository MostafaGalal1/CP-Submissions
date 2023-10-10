#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, count = 1, h = 1, max = 1;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 1; i < n; ++i) {
       if (arr[i] > arr[i-1]) {
           count++;
           h = 1;
       } else {
           if (++h > max)
               max = h;
       }
    }

    cout << max << " " << count << endl;

    return 0;
}